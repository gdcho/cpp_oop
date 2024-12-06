#pragma once

template <typename K, typename V>
class Entry
{
public:
	K key;
	V value;
//	Entry(K key, V value);
	Entry(K key, V value) : key{key}, value{value} {} //declare & define OK
};

//can define constructor outside of class but must be in header file
//template <typename K, typename V>
//Entry<K, V>::Entry(K key, V value) : key{key}, value{value} {}