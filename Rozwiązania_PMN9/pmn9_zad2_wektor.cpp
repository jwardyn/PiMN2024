#include <iostream>

using namespace std;


template<typename T> //nawias <> jak w vectorze z STL'a zadaje nam typ danych wektora [patrz funkcja main()]
class Vector {
private:
 T* data;
size_t size; //size_t mieliście na wykładzie z BZ

public:
    //Dane mają być publiczne, żeby można było na nich operować,
    // nie ma sensu nadawać im statusu prywatnego jeśli chcemy mieć na nich operacje między wektorami
    //gdybyśmy mieli klasę, która robi dużo rzeczy sama i nie potrzebujemy jej wielu instancji to może by to miało sens mieć prywatne
    //ale nie tu
    


    // Constructor
    Vector(size_t sz) : size(sz) {
        data = new T[size]; //  gdzie T jest typem z templatki np double, float
    }                          // a "new" każe przypisać w pamięci nowe miejsce w typie T, dzieje się to dopiero przy wyborze typu, kiedy inicjujemy klasę
    //w tym wypadku zmiana rozmiaru wektora po jego konstrukcji nie jest możliwa [ale nie jest też wymagana w treści zadania]


    // Destructor
    ~Vector() {
        delete[] data; //należy usunąć dynamicznie alokowane (wzięte z "new" ) zasoby, inaczej po pewnym czasie zawali nam pamięć
    }
    





    
    // Przypisanie wartości wektorowi, niszcząc jego dotychczasowy zbiór danych i przypisując nowy
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this; //przez *this zwracamy tę samą klasę
    }




    
    // Porównanie wektorów
    bool operator==(const Vector& other) const {
        if (size != other.size) {
            return false;
        }
        for (size_t i = 0; i < size; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }




    friend ostream& operator<<(ostream& os, const Vector<T>& vec) { //czemu bierzemy tutaj friend? Aby dostać się do prywatnych wartości 
        cout<<endl;
        for (size_t i = 0; i < vec.size; ++i) {
            os << "miejsce: " << i << " wartość:" << vec.data[i] << endl;
        }
        return os;
    }

    friend istream& operator>>(istream& is, Vector<T>& vec) {
        for (size_t i = 0; i < vec.size; ++i) {
            is >> vec.data[i];
        }
        return is;
    }

    
//I mógłbym tutaj też dać jak się robi resztę operatorów ale to jest analogowo do reszty,
// i naprawdę wymaga lekkich zmian w stosunku do powyższych operatorów

};

int main() {
    cout<<"inicjalizacja wektorów:"<<endl;
    size_t n=3;
    Vector<int> vec1(n),vec2(n);// inicjiujemy, gdzie również można inicjować po przecinku
    cout<<"wpisujemy wektor vec1:"<<endl;
    cin>> vec1;// z tym że tutaj akurat mamy cin>> jako strumień wchodzący,
    // a możecie użyć innego strumienia który również wchodzi,
    //tylko że każdy element po kolei przy tej definicji operatora >>, a może być potencjalnie inna



    
    cout << vec1;

    cout<<"wpisujemy wektor vec2:"<<endl;
    cin >> vec2;


    vec1=vec2;

    cout<<" vec1 po przypisaniu wartości vec2:"<<endl;
    cout << vec1;
    cout<<" vec2"<<endl;
    cout << vec2;

    if(vec1==vec2){cout<<"te same"<<endl;}else{cout<<"inne"<<endl;}


    cout<<"koniec"<<endl;



    
    return 0;
}
