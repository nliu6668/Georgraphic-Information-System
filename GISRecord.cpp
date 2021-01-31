#include "GISRecord.h"

     GISRecord::GISRecord(){}
     GISRecord:: ~GISRecord(){}

    string GISRecord::getFeatureId(){return featureId;};
    string GISRecord::getFeatureName(){return featureName;};
    string GISRecord::getFeatureClass(){ return featureClass;};
    string GISRecord::getStateAlpha(){ return stateAlpha; };
    string GISRecord::getStateNumeric(){ return stateNumeric; };
    string GISRecord::getCountryName(){ return countryName; };
    string GISRecord::getCountryNumeric (){ return countryNumeric; };
    string GISRecord::getPrimeLongDms(){ return primeLongDms; };
    string GISRecord::getPrimeLatDms(){ return primeLatDms; };
    string GISRecord::getPrimeLongDec() {return primeLongDec; };
    string GISRecord::getPrimeLatDec (){ return primeLatDec; };
    string GISRecord::getSourceLatDms (){ return sourceLatDms; };
    string GISRecord::getSourceLongDms (){ return sourceLongDms; };
    string GISRecord::getSourceLatDec () { return sourceLatDec; };
    string GISRecord::getSourceLongDec () { return sourceLongDec; };
    string GISRecord::getElevInM () { return elevInM; };
    string GISRecord::getElevInFt(){ return elevInFt; };
    string GISRecord::getMapName(){ return mapName; };
    string GISRecord::getDateCreated(){ return dateCreated; };
    string GISRecord::getDateEdited (){ return dateCreated; };

    void GISRecord::setFeatureId(string _featureId){ featureId = _featureId; };
    void GISRecord::setFeatureName(string _featureName) {featureName = _featureName;};
    void GISRecord::setFeatureClass(string _featureClass) { featureClass = _featureClass; };
    void GISRecord::setStateAlpha(string _stateAlpha) { stateAlpha = _stateAlpha; };
    void GISRecord::setStateNumeric(string _stateNumeric) {stateNumeric = _stateNumeric; };
    void GISRecord::setCountryName(string _countryName) { countryName = _countryName; };
    void GISRecord::setCountryNumeric(string _countryNumeric) {countryNumeric = _countryNumeric; };
    void GISRecord::setPrimeLongDms( string _primeLongDms) {primeLongDms = _primeLongDms;};
    void GISRecord::setPrimeLatDms(string _primeLatDms) { primeLatDms = _primeLatDms; };
    void GISRecord::setPrimeLongDec(string _primeLongDec) {primeLongDec = _primeLongDec; };
    void GISRecord::setPrimeLatDec(string _primeLatDec) {primeLatDec = _primeLatDec; };
    void GISRecord::setSourceLatDms(string _sourceLatDms) { sourceLatDms = _sourceLatDms; };
    void GISRecord::setSourceLongDms(string _sourceLongDms) { sourceLongDms = _sourceLongDms; };
    void GISRecord::setSourceLatDec(string _sourceLatDec) { sourceLatDec = _sourceLatDec; };
    void GISRecord::setSourceLongDec(string _sourceLongDec) {sourceLongDec = _sourceLongDec; };
    void GISRecord::setElevInM(string _elevInM) {elevInM = _elevInM; };
    void GISRecord::setElevInFt(string _elevInFt) {elevInFt = _elevInFt; };
    void GISRecord::setMapName(string _mapName) {mapName = _mapName;};
    void GISRecord::setDateCreated(string _dateCreated) { dateCreated = _dateCreated; };
    void GISRecord::setDateEdited(string _dateEdited) { dateEdited = _dateEdited; };