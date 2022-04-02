#include "PriorityQueue.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>

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
    shift_down(0);
}

void PriorityQueue::clear() {
    elements.clear();
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
    while(i < heap_size) {
        while((i < k) && (i < heap_size)) {
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

void PriorityQueue::shift_down(int current) {
    int left = 2 * current + 1;
    int right = 2 * current + 2;

    int total = size();
    while (left < total && right < total && (elements[left] > elements[current] || elements[right] > elements[current])) {
        int max_ind = elements[left] > elements[current] ? left : right;
        swap(elements[current], elements[max_ind]);
        current = max_ind;
        left = 2 * current + 1;
        right = 2 * current + 2;
    }
}