#include "page.hpp"
#include <iostream>
#include <vector>
//testing Jenkins
using namespace std;

int main(){
   int processSize = 0;
   int pageSize = 0;
   int pageTable = 0;
   int memory = 0;
   int offset = 0;
   
   cout << "Enter the number of locations that the program spans: " << endl;
   cin >> processSize;
   
   cout << "Enter the page/frame size: " << endl;
   cin >> pageSize;
   
   pageTable = processSize / pageSize;
   pageTable = pageTable + 1;
   
   Page pages[pageTable];
   
   cout << "Number of pages: " << pageTable << endl;
   cout << "Page numbers: 0 - " << pageTable - 1 << endl;
   cout << "Enter the frame numbers for the PMT: " << endl;
   
   for(int i = 0; i < pageTable; i++){
      int frame;
      cin >> frame;
      Page *p = new Page(i, frame);
      pages[i] = *p;
   }
   
   cout << "     The PMT is: " << endl;
   cout << endl;
   cout << "   Page#      Frame#" << endl;
   cout << "-------------------------" << endl;
   
   for(int i = 0; i < pageTable; i++){
      cout << pages[i].toString();
      cout << endl;
   }
   
   cout << "Enter the logical memory location in question: " << endl;
   cin >> memory;
   
   cout << memory << " logical memory location will be on page:" << endl;
   cout << "= " << memory << " / page size" << endl;
   cout << "= " << memory << " / " << pageSize << endl;
   double a = double(memory) / pageSize;
   cout << "= " << a << endl;
   int b = int(a) + 1;
   cout << "= " <<  b << "(bump up to the next integer)" << endl;

   cout << "Counting from page # 0, the " << b << "nd/st/th page will be page " << b - 1 << " (#";

   for(int i = 0; i < b; i++){
	if(i == b - 1){
		cout << i << ")" << endl;
	}
	else{
		cout << i << ", ";
	}
   }

   cout << "Number of locations until before the last page: " << endl;
   cout << "= " << pageSize << " x " << b - 1 << endl;
   cout << "= " << pageSize * (b - 1) << " locations" << endl;

   cout << "Number of locations in the last page: " << endl;
   cout << "= " << memory << " - " << pageSize * (b - 1) << endl;

   offset = memory - (pageSize * (b - 1));
   cout << "= " << offset << " locations" << endl;

   offset = offset - 1;

   cout << "Starting from an offset of 0, the " << offset + 1 << "nd/st/th location will be at an offset of " << offset << "." << endl;
   cout << "-------------------------------------------------------------------------------------------------------------" << endl;

   cout << "From the start of the memory map: " << endl;
   cout << "This page is in Frame " << pages[b - 1].getFrameNum() << ", which is the " << pages[b - 1].getFrameNum() + 1 << "st/nd/th by count as we start from frame # 0" << endl;
   cout << "Number of locations covered from start of the map in the first " << pages[b - 1].getFrameNum() << " frames = " << pages[b - 1].getFrameNum() << " x " << pageSize << " = " << pages[b - 1].getFrameNum() * pageSize << " locations" << endl;
   cout << "The last " << offset + 1 << " locations are in Frame # " << pages[b - 1].getFrameNum() << ". Total distance from start = " << pages[b - 1].getFrameNum() * pageSize << " + " << offset + 1 << " = " << pages[b - 1].getFrameNum() * pageSize + offset + 1 << " locations." << endl;
   cout << "So, the " << memory << "st/nd/th location by the logical memory is " << pages[b - 1].getFrameNum() * pageSize + offset + 1 << "nd/st/th location in the physical memory, as per the given PMT." << endl;

   return 0;
}
