Replacing::Replacing():Editor(){
    this->newSubstr = "def";
}

Replacing::Replacing(int valuePosition,Editor::Operation valueOpetarion,
          const string &valueSubstr, string valueNewSubstr):
        Editor(valuePosition,valueOpetarion,
               valueSubstr){
    this->newSubstr = valueNewSubstr;
}

Replacing::~Replacing(){

}

string Replacing::getNewSubstr() const{
    return this->newSubstr;
}

void Replacing::setNewSubstr(string value){
    this->newSubstr = value;
}

int Replacing::identification(){
    return 1;
}







