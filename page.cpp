#include "page.hpp"
#include <string>

Page::Page(){
   setPageNum(0);
   setFrameNum(0);
}

Page::Page(int page, int frame){
   setPageNum(page);
   setFrameNum(frame);
}

void Page::setPageNum(int page){
   this->pageNum = page;
}

void Page::setFrameNum(int frame){
   this->frameNum = frame;
}

int Page::getPageNum(){
   return this->pageNum;
}

int Page::getFrameNum(){
   return this->frameNum;
}

std::string Page::toString(){
   std::string temp = getPageNum() + "          " + getFrameNum();
   return temp;
}
