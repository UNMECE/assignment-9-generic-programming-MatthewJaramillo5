#include<iostream>
#include<stdexcept>

template <typename T>

class GenericArray{
	private: 
		T* data;
   		 int size;

	public: 
		GenericArray() : data(nullptr), size(0) {}
    		~GenericArray() {
        		delete[] data;
   		 }

	void addElement(T param){
		T* newData = new T[size + 1];
		for (int i = 0; i < size; i++) {
            		newData[i] = data[i];
       		 }
        	newData[size] = param;
        	delete[] data;
        	data = newData;
       		size++;
   	 }

	int getSize() const{
		return size;
	}

	T sum() const{
		T total = 0;
		for(int i = 0; i < size; i++){
			total += data[i];
		}
		return total;
	}

	T max() const{
		if(size == 0) throw std::runtime_error("Array is empty");
		T maxval = data[0];
		for (int i = 1; i < size; i++) {
            		if (data[i] > maxval) {
                		maxval = data[i];
            		}
        	}
        	return maxval;
    	}

	T min() const{
		if (size == 0) {
     		       throw std::runtime_error("Array is empty!");
        		}
        	T minval = data[0];
        	for (int i = 0; i < size; i++) {
            		if (data[i] < minval) {
                		minval = data[i];
            			}
        		}
        		return minval;
    		}

	GenericArray<T> slice (int begin, int end)const{
		if(begin < 0 || end > size || begin >= end){
			throw std::out_of_range("Invalid range for the slice");
		}
		GenericArray<T> slicedArray;
		for(int i = begin; i < end; i++){
			slicedArray.addElement(data[i]);
		}
		return slicedArray;
	}

	void print() const{
		for(int i = 0; i < size; i++){
			std::cout << data[i] << " ";
		}
	std::cout << std::endl;
	}
};

int main(){

    GenericArray<int> int_array;
    int_array.addElement(12);
    int_array.addElement(23);
    int_array.addElement(34);
    int_array.addElement(51);
    int_array.addElement(63);

    std::cout << "Size of array is: " << int_array.getSize() << std::endl;
    std::cout << "Sum of the array is: " << int_array.sum() << std::endl;
    std::cout << "Max and min of the array: " << int_array.max() << ", " << int_array.min() << std::endl;

    GenericArray<int> sliced_array = int_array.slice(1, 4);
    std::cout << "Sliced array elements: ";
    sliced_array.print();

    return 0;
}
