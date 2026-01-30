#include <iostream>
#include <vector>
#include <iomanip>

int display_memory(std::vector<unsigned char>& memory, int size); //print the first 16 bytes in the memory on screen

int main(){
    std::vector<unsigned char> memory(1024, 0);
    int address, data;

    std::cout << "SIMPLY MEMORY MANAGER SIMULATOR" << std::endl;

    std::cout << "\nENTER TARGET ADDRESS (0 - 1023): ";
    std::cin >> address;
    
    std::cout << "\nENTER BYTE VALUE (0-255): ";
    std::cin >> data;

    //describes bus write
    if(address >= 0 && address < memory.size()){        //verify the address input
        unsigned char* writer = &memory[address];       //creates the pointer and assign his the memory address by reference
        *writer = static_cast<unsigned char>(data);     //commit data to memory address by dereference after cast his type
        std::cout << "\nSUCESSFULLY WROTE TO MEMORY." << std::endl;
    }else{
        std::cerr << "\nERROR: ADDRESS OUT OF BOUNDS!" << std::endl;
    }

    display_memory(memory, 16); //call the display
}

int display_memory(std::vector<unsigned char>& memory, int size){
    const unsigned char* reader = memory.data();        //create the pointer of the first vector item
    
    std::cout << "\n===MEMORY DUMP (FIRST " << size << " BYTES)===" << std::endl;

    for(int i=0; i < size; i++){
        int value = static_cast<int>(*(reader + i));        //cast the value of the index

        //format and print the value
        std::cout<< std::setw(2) << std::setfill('0') << std::hex << value << " ";
        if((i + 1) %8 == 0){
            std::cout << std::dec << std::endl;
        }
    } 
}