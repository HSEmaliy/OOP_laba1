class Replacing: public Editor{
public:
    Replacing();
    Replacing(int valuePosition,Editor::Operation valueOpetarion,
              const string &valueSubstr, string valueNewSubstr);
    ~Replacing();
    string getNewSubstr() const;
    void setNewSubstr(string value);
    int identification() override;
private:
    string newSubstr;
};







