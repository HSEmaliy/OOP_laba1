using namespace std;
class Story{
public:
    class Iterator;
    class list{
    public:
        Editor * Editor;
        list* next;
    };
    Story();
    Story(const Story& other);
    ~Story();
    int check(Story* other);
    void readFile(const string &namefile);
    void writeFile(const string &namefile);
    void back();
    bool is_empty_first();
    bool is_empty_last();
    void push_back(Editor *neweditor);
    void pop();
    void allDel();
    void setText(string text);
    int getCount() const;
    void getStory();
    list* getFirst() const;
    string getText() const;
    Iterator begin();
    Iterator end();
private:
    int count;
    string text;
    list* first,*last;
};