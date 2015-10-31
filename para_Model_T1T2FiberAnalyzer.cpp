#include "para_Model_T1T2FiberAnalyzer.h"

  para_Model_T1T2FiberAnalyzer::para_Model_T1T2FiberAnalyzer()
  {
    para_DTIComboPath = "" ;
    para_DTIComboSID = "" ;
    para_T12ComboPath = "" ;
    para_T12ComboSID = "" ;
    para_DTIFiber_Path = "" ;
    para_DTIdefInputText = "" ;
    para_T12MapInputText = "" ;
    // para_CSVMatchTable : std::vector<std::vector<QString> > does not require any initialization
    // para_Fiber_Tracts_Table : std::vector<std::vector<QString> > does not require any initialization
}

  QString para_Model_T1T2FiberAnalyzer::getpara_DTIComboPath(){
    return para_DTIComboPath;
  }
  void para_Model_T1T2FiberAnalyzer::setpara_DTIComboPath(QString a){
    para_DTIComboPath=a;
  }
  QString para_Model_T1T2FiberAnalyzer::getpara_DTIComboSID(){
    return para_DTIComboSID;
  }
  void para_Model_T1T2FiberAnalyzer::setpara_DTIComboSID(QString a){
    para_DTIComboSID=a;
  }
  QString para_Model_T1T2FiberAnalyzer::getpara_T12ComboPath(){
    return para_T12ComboPath;
  }
  void para_Model_T1T2FiberAnalyzer::setpara_T12ComboPath(QString a){
    para_T12ComboPath=a;
  }
  QString para_Model_T1T2FiberAnalyzer::getpara_T12ComboSID(){
    return para_T12ComboSID;
  }
  void para_Model_T1T2FiberAnalyzer::setpara_T12ComboSID(QString a){
    para_T12ComboSID=a;
  }
  QString para_Model_T1T2FiberAnalyzer::getpara_DTIFiber_Path(){
    return para_DTIFiber_Path;
  }
  void para_Model_T1T2FiberAnalyzer::setpara_DTIFiber_Path(QString a){
    para_DTIFiber_Path=a;
  }
  QString para_Model_T1T2FiberAnalyzer::getpara_DTIdefInputText(){
    return para_DTIdefInputText;
  }
  void para_Model_T1T2FiberAnalyzer::setpara_DTIdefInputText(QString a){
    para_DTIdefInputText=a;
  }
  QString para_Model_T1T2FiberAnalyzer::getpara_T12MapInputText(){
    return para_T12MapInputText;
  }
  void para_Model_T1T2FiberAnalyzer::setpara_T12MapInputText(QString a){
    para_T12MapInputText=a;
  }
  std::vector<std::vector<QString> > para_Model_T1T2FiberAnalyzer::getpara_CSVMatchTable(){
    return para_CSVMatchTable;
  }
  void para_Model_T1T2FiberAnalyzer::setpara_CSVMatchTable(std::vector<std::vector<QString> > a){
    if( !a.empty() )
    {
      std::vector<std::vector<QString> >::iterator it = a.begin(); 
      std::vector<std::vector<QString> >::size_type first_size = a[0].size();
      for( ; it != a.end() ; ++it )
      {
        if( it->size() != first_size )
        {
          throw std::runtime_error("Failed: All rows do not have the same size");
        }
      }
    }
    para_CSVMatchTable=a;
  }
  std::vector<std::vector<QString> > para_Model_T1T2FiberAnalyzer::getpara_Fiber_Tracts_Table(){
    return para_Fiber_Tracts_Table;
  }
  void para_Model_T1T2FiberAnalyzer::setpara_Fiber_Tracts_Table(std::vector<std::vector<QString> > a){
    if( !a.empty() )
    {
      std::vector<std::vector<QString> >::iterator it = a.begin(); 
      std::vector<std::vector<QString> >::size_type first_size = a[0].size();
      for( ; it != a.end() ; ++it )
      {
        if( it->size() != first_size )
        {
          throw std::runtime_error("Failed: All rows do not have the same size");
        }
      }
    }
    para_Fiber_Tracts_Table=a;
  }
