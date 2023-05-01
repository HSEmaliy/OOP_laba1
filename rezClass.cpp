using namespace std;
void Editor::setPosition(int valuePosition) {
    this->position = valuePosition;
}

void Editor::setOperation(Operation valueOperation) {
    this->predOperation = valueOperation;
}

void Editor::setSubstr(const string &valueSubstr){
    this->substr = valueSubstr;
}

int Editor::getPosition() const {
    return this->position;
}

Editor::Operation Editor::getOperation() const {
    return this->predOperation;
}

string Editor::getSubstr() const {
    return this->substr;
}

int Editor::identification(){
    return 0;
}

Editor::Editor(int valuePosition,Editor::Operation valueOpetarion,const string &valueSubstr){
    this->position = valuePosition;
    this->predOperation = valueOpetarion;
    this->substr = valueSubstr;
}
//    конструктор по умолчанию
Editor::Editor(){
    this->position = 0;
    this->predOperation = BY_DEFAULT;
    this->substr = " ";
}
//    конструктор копирования
Editor::Editor(const Editor &other){
    this->position = other.position;
    this->predOperation= other.predOperation;
    this->substr = other.substr;
}
// деструктор
Editor::~Editor(){
//    cout<<"Destructor called!"<<endl;
}