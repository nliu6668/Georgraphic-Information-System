#include <iostream>
#include <fstream>
#include <string>

using namespace std;
typedef struct Date{
    Date(){};
    Date(int _year, int _month, int _day):year(_year),month(_month),day(_day){};
   int year;
   int month;
   int day;
   inline void setYear(int _year){ year = _year;};
   inline void setMonth(int _month){ month = _month;};
   inline void setDay(int _day){day = _day;};
   inline int getYear(){ return year; };
   inline int getMonth(){ return month; };
   inline int getDay(){ return day; };
}Date;

class GISRecord{
    public:
    GISRecord();
     GISRecord(string _featureId,//1
    string _featureName,//2
    string _featureClass,//3
    string _stateAlpha,//4
    string _stateNumeric,//5
    string _countryName,//6
    string _countryNumeric, //7
    string _primeLatDms, //8
    string _primeLongDms, //9
    string _primeLatDec, //10
    string _primeLongDec, //11
    string _sourceLatDms, //12
    string _souceLongDms, //13
    string _sourceLatDec, //14
    string _sourceLongDec, //15
    string _elevInM, //16
    string _elevInFt, //17
    string _mapName, //18
    string _dateCreated, //19
    string _dateEdited): 
    featureId(_featureId),
    featureName(_featureName),
    featureClass(_featureClass),
    stateAlpha( _stateAlpha),
    stateNumeric(_stateNumeric),
    countryName(_countryName),
    countryNumeric(_countryNumeric),
    primeLatDms(_primeLatDms),
    primeLongDms(_primeLongDms),
    primeLatDec( _primeLatDec),
    primeLongDec(_primeLongDec),
    sourceLatDms(_sourceLatDms),
    sourceLongDms(_souceLongDms),
    sourceLatDec(_sourceLatDec),
    sourceLongDec(_sourceLongDec),
    elevInM(_elevInM),
    elevInFt(_elevInFt),
    mapName(_mapName),
    dateCreated(_dateCreated),
    dateEdited(_dateEdited){};

    ~GISRecord();

    string getFeatureId();
    string getFeatureName();
    string getFeatureClass();
    string getStateAlpha();
    string getStateNumeric();
    string getCountryName();
    string getCountryNumeric ();
    string getPrimeLongDms();
    string getPrimeLatDms();
    string getPrimeLongDec();
    string getPrimeLatDec ();
    string getSourceLatDms ();
    string getSourceLongDms ();
    string getSourceLatDec ();
    string getSourceLongDec ();
    string getElevInM ();
    string getElevInFt();
    string getMapName();
    string getDateCreated();
    string getDateEdited ();

    void setFeatureId(string _featureId);
    void setFeatureName(string _featureName);
    void setFeatureClass(string _featureClass);
    void setStateAlpha(string _stateAlpha);
    void setStateNumeric(string _stateNumeric);
    void setCountryName(string _countryName);
    void setCountryNumeric(string _countryNumeric);
    void setPrimeLongDms( string _primeLongDms);
    void setPrimeLatDms(string _primeLatDms) ;
    void setPrimeLongDec(string _primeLongDec);
    void setPrimeLatDec(string _primeLatDec);
    void setSourceLatDms(string _sourceLatDms);
    void setSourceLongDms(string _sourceLongDms);
    void setSourceLatDec(string _sourceLatDec);
    void setSourceLongDec(string _sourceLongDec) ;
    void setElevInM(string _elevInM);
    void setElevInFt(string _elevInFt);
    void setMapName(string _mapName) ;
    void setDateCreated(string _dateCreated);
    void setDateEdited(string _dateEdited)                                                                                                                                                                                          ;

    private:
    string featureId; // 1. FEATURE_ID
    string featureName;//2. FEATURE_NAME
    string featureClass; //3. FEATURE_CLASS
    string stateAlpha; //4. sTATE_ALPHA
    string stateNumeric; //5. sTATE_NUMERIC
    string countryName; //6. COUNTY_NAME
    string countryNumeric;//7. COUNTY_NUMERIC
    string primeLatDms; //8. |PRIMARY_LAT_DMS
    string primeLongDms; //9. PRIM_LONG_DMS
    string primeLatDec; //10. PRIM_LAT_DEC
    string primeLongDec; //11. PRIM_LONG_DEC
    string sourceLatDms; //12. SOURCE_LAT_DMS
    string sourceLongDms; //13. SOURCE_LONG_DMS
    string sourceLatDec; //14. SOURCE_LAT_DEC
    string sourceLongDec; //15. SOURCE_LONG_DEC
    string elevInM; //16. ELEV_IN_M
    string elevInFt; //17. ELEV_IN_FT
    string mapName; //18. MAP_NAME
    string dateCreated; //19. DATE_CREATED
    string dateEdited; //20. DATE_EDITED
};