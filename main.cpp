#include "page.hpp"
#include <iostream>

using namespace std;

int main(){
   int processSize = 0;
   int pageSize = 0;
   int pageTable = 0;
   int memory = 0;
   vector<Page> pages;
   
   cout << "Enter the number of lacations that the program spans: " << endl;
   cin >> processSize;
   
   cout << "Enter the page/frame size: " << endl;
   cin >> pageSize;
   
   pageTable = processSize / pageSize;
   pageTable = pageTable + 1;
   
   pages.resize(pageTable);
   
   cout << "Number of pages: " << pageTable << endl;
   cout << "Page numbers: 0 - " << pageTable - 1 << endl;
   cout << "Enter the frame numbers for the PMT: " << endl;
   
   for(int i = 0; i < pageTable; i++{
      int frame;
      cin >> frame;
      Page p = new Page(i, frame);
      pages.insert(i, p);
   }
   
   cout << "     The PMT is: " << endl;
   cout << endl;
   cout << "---------------------" << endl;
   
   for(int i = 0; i < pageTable; i++){
      cout << pages.at(i).toString();
      cout << endl;
   }
   
   cout << "Enter the logical memory location in question: " << endl;
   cin >> memory;
   
   cout << memory << " logical memory location will be on page:" << endl;
   cout << "= " << memory << " / page size" << endl;
   cout << "= " << memory << " / " << pageSize << endl;
}