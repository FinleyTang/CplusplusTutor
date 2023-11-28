//
// Created by ftang on 2023/11/27.
//

template <typename T>
Pair<T>::Pair(T first, T second):m_first(first), m_second(second) {

}

template <typename T>
T Pair<T>::get_first(){
    return m_first;
}
template <typename T>
T Pair<T>::get_second(){
    return m_second;
}