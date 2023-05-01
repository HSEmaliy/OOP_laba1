using namespace std;
class Editor{
public:
    enum Operation{
        INSERT,
        DELETE,
        REPLACING,
        BY_DEFAULT
    };
    Editor();
    Editor(int valuePosition,Editor::Operation valueOpetarion,const string &valueSubstr);
    Editor(const Editor &other);
    ~Editor();
    void setPosition(int valuePosition);
    void setOperation(Operation valueOperation);
    void setSubstr(const string &valueSubstr);
    int getPosition() const;
    Operation getOperation() const;
    string getSubstr() const;
    virtual int identification();

private:
    int position;
    Operation predOperation;
    string substr;
};