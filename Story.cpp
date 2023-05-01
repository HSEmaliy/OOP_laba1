class Story::Iterator{
private:
    list* cur;
public:
    Iterator(list* fir){
        this->cur = fir;
    }
//    Перегрузки операторов
    list* operator*(){return cur;}
    list& operator++(){
        this->cur = this->cur->next;
        return *this->cur;
    }
    bool operator!=(const Iterator &it){return cur!=it.cur;}
    bool operator==(const Iterator &it){return cur == it.cur;}
};

Story::Iterator Story::begin(){
    return this->first;
}

Story::Iterator Story::end(){
    return this->last;
}

Story::Story(){
    this->count = 0;
    this->text = "random text";
    this->first = nullptr;
}

Story::Story(const Story& other){
    auto it = Iterator(other.first);
    list* pred;
    list *current = new list;
    current->Editor->setPosition((*it)->Editor->getPosition());
    current->Editor->setOperation((*it)->Editor->getOperation());
    current->Editor->setSubstr((*it)->Editor->getSubstr());
    this->first = current;
    pred = current;
    ++it;
    for(it;it!= nullptr;++it){
        current = new list;
        current->Editor->setPosition((*it)->Editor->getPosition());
        current->Editor->setOperation((*it)->Editor->getOperation());
        current->Editor->setSubstr((*it)->Editor->getSubstr());
        pred->next = current;
        pred = current;
    }
    pred->next = nullptr;
    this->text = other.text;
    this->count = other.count;
}

Story::~Story(){
    allDel();
}

int Story::check(Story* other){
    auto it = Iterator(Story::begin());
    auto iter = Iterator(other->Story::begin());
    if(this->getCount()!=other->getCount() || this->text!=other->text)
        return 0;

    while(it!=nullptr || iter!=nullptr){
        if((*it)->Editor->getPosition() != (*iter)->Editor->getPosition())
            break;
        else if((*it)->Editor->getOperation() != (*iter)->Editor->getOperation())
            break;
        else if((*it)->Editor->getSubstr() != (*iter)->Editor->getSubstr())
            break;
        ++it;
        ++iter;
    }
    if(it==nullptr && iter==nullptr) return 1;
    else return 0;
}

void Story::readFile(const string &namefile){
    int a;
    string b;
    fstream file;
    file.open(namefile);
    getline(file >> ws,this->text);
    while(!file.eof()){
        Editor editor;
        file >> a;
        editor.setPosition(a);

        getline(file >> ws, b);
        if(b == "INSERT")
            editor.setOperation(Editor::Operation::INSERT);
        else if(b == "DELETE")
            editor.setOperation(Editor::Operation::DELETE);
        else if(b =="REPLACING")
            editor.setOperation(Editor::Operation::REPLACING);
        else
            editor.setOperation(Editor::Operation::BY_DEFAULT);


        getline(file >> ws, b);
        editor.setSubstr(b);
        push_back(&editor);
    }
}

void Story::writeFile(const string &namefile){
    ofstream file;
    file.open(namefile);
    file << Story::getText()<<endl;
    auto it = Iterator(Story::begin());
    for(it;it!= nullptr;++it) {
        file <<(*it)->Editor->getPosition()<<endl;
        if((*it)->Editor->getOperation() == Editor::Operation::INSERT)
            file <<"INSERT\n";
        else if((*it)->Editor->getOperation() == Editor::Operation::DELETE)
            file <<"DELETE\n";
        else if((*it)->Editor->getOperation() == Editor::Operation::REPLACING)
            file <<"REPLACING\n";
        else
            file <<"BY_DEFAULT\n";

        file <<(*it)->Editor->getSubstr()<<endl;
    }
}

void Story::back(){
    this->count--;
    list* d;
    if(first->Editor->getOperation() == Editor::INSERT){
        int l = first->Editor->getSubstr().length();
        this->text = this->text.erase(this->first->Editor->getPosition(),l);
        d = this->first;
        this->first = this->first->next;
        delete d;
    }
    else if(first->Editor->getOperation() == Editor::REPLACING){
        Replacing *cur = ((Replacing *)first->Editor);
        int l = cur->getSubstr().length();
        this->text = this->text.erase(cur->getPosition(),l);
        this->text.insert(cur->getPosition(),cur->getNewSubstr());
    }
    else{
        this->text.insert(this->first->Editor->getPosition(),this->first->Editor->getSubstr());
        d = this->first;
        this->first = this->first->next;
        delete d;
    }
}

void Story::setText(string text) {
    this->text = text;
}

bool Story::is_empty_first() {
    return this->first == nullptr;
}
//Этот метод добавляет новый объект класса в коллекцию
void Story::push_back(Editor *neweditor){
    count++;
    list * current;
    if(neweditor->identification() == 1){
        Replacing *g = ((Replacing* )neweditor);
        Replacing * edit = new Replacing;
        edit->setOperation(g->getOperation());
        edit->setPosition(g->getPosition());
        edit->setSubstr(g->getSubstr());
        edit->setNewSubstr(g->getNewSubstr());
        current = new list;
        current->Editor = edit;
        if(is_empty_first()){
            this->last = current;
        }
        current->next = this->first;
        this->first = current;
    }
    else{
        Editor * edit = new Editor;
        edit->setOperation(neweditor->getOperation());
        edit->setPosition(neweditor->getPosition());
        edit->setSubstr(neweditor->getSubstr());
        current = new list;
        current->Editor = edit;
        if(is_empty_first()){
            this->last = current;
        }
        current->next = this->first;
        this->first = current;
    }
    this->first = current;
}
bool Story::is_empty_last() {
    return this->first->next == nullptr;
}
void Story::pop(){
    this->count--;
    if(is_empty_last()){
        cout<<"if\n";
        delete this->first;
        this->first = nullptr;
        this->last = nullptr;
    }else {
        list *current = *(Story::begin());
        this->first = this->first->next;
        delete current;
    }
}

void Story::allDel(){
    this->count = 0;
    list *current = this->first;
    while(current!= nullptr){
        current = current->next;
        delete first;
        first = current;
    }
    cout<<"full delete!\n";
}

int Story::getCount() const{
    return this->count;
}

string Story::getText() const{
    return this->text;
}

void Story::getStory() {
    auto it = Iterator(Story::begin());
    for(it;it!= nullptr;++it){
        cout<<endl;
        cout<<"position: "<<(*it)->Editor->getPosition()<<endl;
        cout<<"state: "<<(*it)->Editor->getOperation()<<endl;
        cout<<"substr: "<<(*it)->Editor->getSubstr()<<endl;
        cout<<endl;
    }
}

Story::list* Story::getFirst() const{
    return this->first;
}

void get(Story& story){
    int i = 0;
    auto it = Story::Iterator(story.begin());
    for(it;it!= nullptr;++it){
        cout<<endl;
        cout<<"object classa #"<<i<<":"<<endl;
        cout<<"position: "<<(*it)->Editor->getPosition()<<endl;
        cout<<"state: "<<(*it)->Editor->getOperation()<<endl;
        cout<<"substr: "<<(*it)->Editor->getSubstr()<<endl;
        cout<<endl;
        i++;
    }
}