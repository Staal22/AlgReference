// template <typename T>
// NodeT<T>::NodeT(T _data) {
//     data = _data;
// }
//
// template <typename T>
// void NodeT<T>::Insert(T newData) {
//     if (newData < data) {
//         if (l != nullptr) {
//             l->Insert(newData);
//             return;
//         }
//         else {
//             // we are at leaf
//             l = new NodeT(newData);
//             return;
//         }
//     }
//     else {
//         if (r != nullptr) {
//             r->Insert(newData);
//             return;
//         }
//         else {
//             // we are at leaf
//             r = new NodeT(newData);
//             return;
//         }
//     }
// }
//
// template <typename T>
// int NodeT<T>::Find(int number) {
//     return 0;
// }
//
// template <typename T>
// void NodeT<T>::Clear() {
// }
//
// template <typename T>
// int NodeT<T>::Size() {
// }
//
// template <typename T>
// void NodeT<T>::ToStringInOrder(std::string& someText) {
// }
//
// template <typename T>
// void NodeT<T>::ToStringPreOrder(std::string& someText) {
// }
//
// template <typename T>
// void NodeT<T>::ToStringPostOrder(std::string& someText) {
// }
//
// template <typename T>
// void NodeT<T>::PrintTree() {
// }
//
// template <typename T>
// void NodeT<T>::GetActualSize(int& size) {
// }
//
// template <typename T>
// void NodeT<T>::GetDepthValuePair(std::vector<std::pair<int, int>>& list, int depth) {
// }
