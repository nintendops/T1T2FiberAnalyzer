#include "Model_T1T2FiberAnalyzer.h"

  QString Model_T1T2FiberAnalyzer::getDTIComboPath(){
    return DTIComboPath;
  }
  void Model_T1T2FiberAnalyzer::setDTIComboPath(QString a){
    DTIComboPath=a;
  }
  QString Model_T1T2FiberAnalyzer::getDTIComboSID(){
    return DTIComboSID;
  }
  void Model_T1T2FiberAnalyzer::setDTIComboSID(QString a){
    DTIComboSID=a;
  }
  QString Model_T1T2FiberAnalyzer::getT12ComboPath(){
    return T12ComboPath;
  }
  void Model_T1T2FiberAnalyzer::setT12ComboPath(QString a){
    T12ComboPath=a;
  }
  QString Model_T1T2FiberAnalyzer::getT12ComboSID(){
    return T12ComboSID;
  }
  void Model_T1T2FiberAnalyzer::setT12ComboSID(QString a){
    T12ComboSID=a;
  }
  QString Model_T1T2FiberAnalyzer::getDTIFiber_Path(){
    return DTIFiber_Path;
  }
  void Model_T1T2FiberAnalyzer::setDTIFiber_Path(QString a){
    DTIFiber_Path=a;
  }
  QString Model_T1T2FiberAnalyzer::getDTIStatPath(){
    return DTIStatPath;
  }
  void Model_T1T2FiberAnalyzer::setDTIStatPath(QString a){
    DTIStatPath=a;
  }
  QString Model_T1T2FiberAnalyzer::getDTIdefInputText(){
    return DTIdefInputText;
  }
  void Model_T1T2FiberAnalyzer::setDTIdefInputText(QString a){
    DTIdefInputText=a;
  }
  QString Model_T1T2FiberAnalyzer::getFiberProcessPath(){
    return FiberProcessPath;
  }
  void Model_T1T2FiberAnalyzer::setFiberProcessPath(QString a){
    FiberProcessPath=a;
  }
  QString Model_T1T2FiberAnalyzer::getT12MapInputText(){
    return T12MapInputText;
  }
  void Model_T1T2FiberAnalyzer::setT12MapInputText(QString a){
    T12MapInputText=a;
  }
  QString Model_T1T2FiberAnalyzer::getpyPath(){
    return pyPath;
  }
  void Model_T1T2FiberAnalyzer::setpyPath(QString a){
    pyPath=a;
  }
  std::map<QString,bool> Model_T1T2FiberAnalyzer::getCSVMatchTable(){
    return CSVMatchTable;
  }
  void Model_T1T2FiberAnalyzer::setCSVMatchTable(std::map<QString,bool> a){
    CSVMatchTable=a;
  }
  std::map<QString,bool> Model_T1T2FiberAnalyzer::getFiber_Tracts_Table(){
    return Fiber_Tracts_Table;
  }
  void Model_T1T2FiberAnalyzer::setFiber_Tracts_Table(std::map<QString,bool> a){
    Fiber_Tracts_Table=a;
  }
