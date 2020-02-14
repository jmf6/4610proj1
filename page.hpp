#ifndef PAGE_HPP
#define PAGE_HPP
#include <string>

class Page{
   private:
      int pageNum;
      int frameNum;
      void setPageNum(int page);
      void setFrameNum(int frame);
      int getPageNum();
      int getFrameNum();
      
   public:
      Page();
      Page(int page, int frame);
      std::string toString();
};

#endif