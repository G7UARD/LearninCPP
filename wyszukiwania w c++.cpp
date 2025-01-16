#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

//1
/*int wyszukiwanie(int tablica[], int rozmiar, int cel) {
    
    for (int i = 0; i < rozmiar; i++) {
        if (tablica[i] == cel) {
            return i;
        }
    }
    return -1; 
}

int main(){
    const int rozmiar = 100;
    int tablica[rozmiar];
    int cel;
    

    for (int i = 0; i < rozmiar; i++) {
        tablica[i] = i + 1;
    }
    
    cout << "Wyszukaj numer (1 - 100): ";
    cin >> cel;

    int rezultat = wyszukiwanie(tablica, rozmiar, cel);

    if (rezultat != -1) {
        cout << "Twoj numer znalezniony na indeksie: " << rezultat << endl;
    }
    else {
        cout << "Twojego numeru nie znaliezniono tablice!" << endl;
    }

    return(0);
}
*/
//2
/*int wyszukiwanie(int tablica[], int rozmiar, int cel) {

    for (int i = 0; i < rozmiar; i++) {
        if (tablica[i] == cel) {
            return i;
        }
    }
    return -1;
}

int main() {
    const int rozmiar = 100;
    int tablica[rozmiar];
    int cel;


    for (int i = 0; i < rozmiar; i++) {
        tablica[i] = i + 1;
    }

    cout << "Wyszukaj numer (1 - 100). Nacisnij -1 zeby skonczyc program   ";

    while (true) {
        cin >> cel;
        if (cel == -1) { //wartownik
            break;
        }


        int rezultat = wyszukiwanie(tablica, rozmiar, cel);

        if (rezultat != -1) {
            cout << "Twoj numer znalezniony na indeksie: " << rezultat << endl;
        }
        else {
            cout << "Twojego numeru nie znaliezniono tablice!" << endl;
        }
        break;
    }

    return(0);
}
*/   
//3
/*int binarneW(const vector<int>& tablica, int cel) {
    int left = 0;
    int right = tablica.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        
        if (tablica[mid] == cel) {
            return mid; 
        }
        
        else if (tablica[mid] > cel) {
            right = mid - 1;
        }
        
        else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    const int rozmiar = 100;
    vector<int> tablica(rozmiar);
    int cel;

    cout << "Wpisz numer do wyszukiwania: ";
    cin >> cel;

    for (int i = 0; i < rozmiar; i++) {
        tablica[i] = i + 1;
    }
    


    int rezultat = binarneW(tablica, cel);

    if (rezultat != -1) {
        cout << "Twoj numer znalezniony na indeksie:: " << rezultat << endl;
    }
    else {
        cout << "Twojego numeru nie znaliezniono tablice!" << endl;
    }

    return 0;
}
*/
//4
/*int linearSearch(const vector<int>& tablica, int cel) {
    for (int i = 0; i < tablica.size(); i++) {
        if (tablica[i] == cel) {
            return i;  
        }
    }
    return -1;  
}
   
int wSearch(vector<int>& tablica, int cel) {
    int n = tablica.size();
    int wartownik = cel;
    tablica.push_back(wartownik);

    int i = 0;
    while (tablica[i] != wartownik) {
        if (tablica[i] == cel) {
            tablica.pop_back();
            return i;
        }
        i++;
    }
}
    
int binarneW(const vector<int>&tablica, int cel) {
        int left = 0;
        int right = tablica.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (tablica[mid] == cel) {
                return mid;  
            }
            else if (tablica[mid] > cel) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;  
}

int main() {
    const int rozmiar = 1000000;  
    vector<int> tablica(rozmiar);

    
    for (int i = 0; i < rozmiar; i++) {
        tablica[i] = i + 1;
    }

    int cel = rozmiar;  

    
    auto start = high_resolution_clock::now();
    int result = linearSearch(tablica, cel);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Czas liniowego wyszukiwania: " << duration.count() << " mikrosekund" << endl;

    
    start = high_resolution_clock::now();
    result = wSearch(tablica, cel);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Czas wyszukiwania z wartowmikiem: " << duration.count() << " mikrosekund" << endl;

    
    start = high_resolution_clock::now();
    result = binarneW(tablica, cel);
    end = high_resolution_clock::now();
    duration = duration_cast<microseconds>(end - start);
    cout << "Czas binarnego wyszukiwania: " << duration.count() << " mikrosekund" << endl;

    return 0;
}
*/
//5
/*
struct Node {
    int data;         
    Node* next;       
    Node* prev;       

   
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};


class DoublyLinkedList {
private:
    Node* head;  
    Node* tail;  

public:
   
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    
    void append(int value) {
        Node* newNode = new Node(value);

        if (tail == nullptr) {  
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    
    void removeAt(int position) {
        if (head == nullptr) {
            cout << "Список пуст!" << endl;
            return;
        }

        Node* current = head;

        
        int count = 0;
        while (current != nullptr && count < position) {
            current = current->next;
            count++;
        }

        
        if (current == nullptr) {
            cout << "Неверная позиция!" << endl;
            return;
        }

        
        if (current == head) {
            head = current->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
        }
        
        else if (current == tail) {
            tail = current->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        }
        
        else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;  
    }

    
    void printList() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};


int main() {
    DoublyLinkedList list;

    
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    cout << "Список перед удалением: ";
    list.printList();

    
    list.removeAt(2);

    cout << "Список после удаления элемента на позиции 2: ";
    list.printList();

    
    list.removeAt(10);  

    return 0;
}
*/


