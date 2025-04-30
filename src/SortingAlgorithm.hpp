#pragma once

#include <iostream>
#include <vector>
#include <concepts>

using namespace std;

namespace SortLibrary {

template <typename T>
concept Sortable = requires(T &t) {
    {t < t} -> std::convertible_to<bool>;
};

template<Sortable T>
    void BubbleSort(std::vector<T>& v){
        for(unsigned int i = 0; i < v.size()-1; i++){
            for(unsigned int j = 0; j < v.size()-1-i; j++){
                if (v[j] > v[j+1]){
                    T a = v[j];
                    v[j] = v[j+1];
                    v[j+1] = a;
                }
            }
        }
    }

template<Sortable T>
    void HeapSort(std::vector<T>& v){
        std::vector<int> heap;
        for(unsigned int i = 0; i < v.size(); i++){
            heap.push_back(v[i]);
            std::push_heap(heap.begin(), heap.end(), std::greater<>());
        }


        unsigned int i = 0;
        while(!heap.empty()){
            std::pop_heap(heap.begin(), heap.end(), std::greater<>()); // Sposta l'elemento massimo alla fine
            v[i] = heap.back();   // Aggiungilo al vettore ordinato
            heap.pop_back();  // Rimuovilo dall'heap
            i++;
        }

    }

}


