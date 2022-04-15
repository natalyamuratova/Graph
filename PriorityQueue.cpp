#include "PriorityQueue.h"
#include <algorithm>
#include <string>
#include <iostream>

using std::swap;
using std::string;
using std::cout;
using std::endl;

PriorityQueue::PriorityQueue() = default;

PriorityQueue::~PriorityQueue() {
    clear();
}

void PriorityQueue::push(int value) {
    elements.push_back(value);
    shift_up(size() - 1);
}

int PriorityQueue::top() {
    if (is_empty()) {
        throw string("Queue is empty!");
    }

    return elements.front();
}

void PriorityQueue::pop() {
    if (is_empty()) {
        throw string("Queue is empty!");
    }

    elements[0] = elements.back();
    elements.pop_back();
    shift_down(0, size());
}

void PriorityQueue::clear() {
    elements.clear();
}

void PriorityQueue::sort() {
    for (int i = size() - 1; i >= 0; i--) {
        swap(elements[0], elements[i]);
        shift_down(0, i);
    }
}

void PriorityQueue::print_as_array() {
    for (int el: elements) {
        cout << el << " ";
    }
    cout << endl;
}

void PriorityQueue::print_as_tree() {
    int i = 0;
    int k = 1;
    int heap_size = size();
    while (i < heap_size) {
        while ((i < k) && (i < heap_size)) {
            cout << elements[i] << " ";
            i++;
        }
        cout << endl;
        k = k * 2 + 1;
    }
    cout << endl;
}

int PriorityQueue::size() {
    return elements.size();
}

bool PriorityQueue::is_empty() {
    return size() == 0;
}

void PriorityQueue::shift_up(int current) {
    int parent = (current - 1) / 2;

    while (current > 0 && elements[parent] < elements[current]) {
        swap(elements[current], elements[parent]);
        current = parent;
        parent = (current - 1) / 2;
    }
}

void PriorityQueue::shift_down(int current, int n) {
    int largest = current;
    int l = 2 * current + 1;
    int r = 2 * current + 2;

    while ((l < n && elements[largest] < elements[l]) || (r < n && elements[largest] < elements[r])) {
        if (l < n && elements[l] > elements[largest])
            largest = l;

        if (r < n && elements[r] > elements[largest])
            largest = r;

        if (largest != current) {
            swap(elements[current], elements[largest]);
            current = largest;
            l = 2 * current + 1;
            r = 2 * current + 2;
        }
    }
}