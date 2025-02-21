// REFERENCE Sten Rune Lyngmo https://github.com/STEN1/algoritmer_datastrukturer/blob/main/Oblig3/Eksamen2019Oppgave4abDijkstra.cpp
#include <iostream>
#include <list>
#include <queue>


struct Kant;
struct Node
{
	char m_navn;
	bool m_besokt;
	std::list<Kant> m_kanter;
	Node(char navn) : m_navn(navn), m_besokt(false) {}
	void settinn_kant(const Kant& kant) { m_kanter.push_back(kant);	}
};
struct Kant
{
	float m_vekt;
	Node* m_tilnode;
	Kant(float vekt, Node* tilnode) : m_vekt(vekt), m_tilnode(tilnode) { }
	// bool operator > (const Kant& k) const { return m_vekt > k.m_vekt; }
	operator float() const { return m_vekt; }
};
struct Vei
{
	std::vector<Kant> m_kanter;
	float KalkulerLengde() const
	{
		float lengde{};
		for (auto& kant : m_kanter)
			lengde += kant.m_vekt;
		return lengde;
	}
	Node* GetLastNode() const
	{
		if (!m_kanter.empty())
		{
			return m_kanter[m_kanter.size() - 1].m_tilnode;
		}
		return nullptr;
	}
	void Print()
	{
		std::cout << "Vei: ";
		for (auto& kant : m_kanter)
			std::cout << kant.m_tilnode->m_navn;
		std::cout << " (" << *this << ")" << std::endl;
	}
	operator float() const { return KalkulerLengde(); }
};
struct Graf
{
	std::list<Node*> noder;
	Graf() { }
	Node* finn_node(char navn)
	{
		for (auto node : noder)
			if(node->m_navn == navn)
				return node;
		return nullptr;
	}
	void settinn_node(char navn) 
	{
		noder.push_back(new Node(navn)); 
	}
	void settinn_kant(char fra_navn, char til_navn, float vekt)
	{
		Node* fra = nullptr;
		Node* til = nullptr;
		for (auto node : noder)
		{
			if (node->m_navn == fra_navn)
				fra = node;
			else if (node->m_navn == til_navn)
				til = node;
		}
		if (fra && til)
			fra->settinn_kant({ vekt, til });
	}
	float mst() // Prim
	{
		float sum{};
		std::priority_queue<Kant, std::vector<Kant>, std::greater<Kant>> apq;
		apq.emplace(0.f, noder.front());
		do
		{
			auto kant = apq.top();
			auto node = kant.m_tilnode;
			apq.pop();
			if (!node->m_besokt)
			{
				sum += kant.m_vekt;
				node->m_besokt = true;
				std::cout << kant.m_tilnode->m_navn;
				for (auto& kant : node->m_kanter)
					apq.push(kant);
			}
		} while (!apq.empty());
		return sum;
	}
	Vei Dijkstra(Node* start, Node* end)
	{
		std::priority_queue<Vei, std::vector<Vei>, std::greater<Vei>> apq;
		std::vector<Node*> visited;
		// setup
		Kant startKant{ 0.f, start };
		Vei startVei;
		startVei.m_kanter.push_back(startKant);
		apq.push(startVei);
		Vei kortesteVei;
		while (!apq.empty()/* && !end->m_besokt*/)
		{
			Node* tempNode = apq.top().GetLastNode();
			if (tempNode == end)
			{
				kortesteVei = apq.top(); // bare å returnere denne hær egentlig
				break;
			}
			Vei tempVei = apq.top();
			apq.pop();
			tempNode->m_besokt = true;
			visited.push_back(tempNode);
			for (auto& kant : tempNode->m_kanter)
			{
				if (!kant.m_tilnode->m_besokt)
				{
					Vei nyVei = tempVei;
					nyVei.m_kanter.push_back(kant);
					nyVei.Print();
					apq.push(nyVei);
				}
			}
			std::cout << std::endl;
		}

		for (auto node : visited)
			node->m_besokt = false;

		std::cout << "Korteste vei: ";
		for (auto& kant : kortesteVei.m_kanter)
			std::cout << kant.m_tilnode->m_navn;
		std::cout << " (" << kortesteVei << ")" << std::endl;

		return kortesteVei;
	}
};


int maain()
{
	Graf graf;
	graf.settinn_node('A');
	graf.settinn_node('B');
	graf.settinn_node('C');
	graf.settinn_node('D');
	graf.settinn_node('E');

	graf.settinn_kant('A', 'B', 1.f);
	graf.settinn_kant('A', 'C', 2.f);
	graf.settinn_kant('B', 'C', 2.f);
	graf.settinn_kant('C', 'D', 3.f);
	graf.settinn_kant('D', 'E', 1.f);
	graf.settinn_kant('A', 'E', 5.f);
	graf.settinn_kant('C', 'E', 4.f);

	for (auto node : graf.noder)
	{
		std::cout << "Node: " << node->m_navn << " Kanter: ";
		for (auto& kant : node->m_kanter)
			std::cout << node->m_navn << kant.m_tilnode->m_navn << "(" << kant.m_vekt << "), ";
		std::cout << std::endl;
	}
	graf.Dijkstra(graf.finn_node('A'), graf.finn_node('D'));

	std::cout << graf.mst() << std::endl;
	return 0;
}