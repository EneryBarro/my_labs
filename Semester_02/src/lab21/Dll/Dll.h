
#ifdef ZOODLL_EXPORTS  
#define ZOO_API __declspec(dllexport)   
#else  
#define ZOO_API __declspec(dllimport)   
#endif  

class ZOO_API Zoo
{
private:
    char name[50];
    int number;
    char colour[50];
    char continent[50];
    char kind[50];
    int age;
public:
    static void console_clear();
    void form_file();
    void read_file();
    void work_file();
    void add_Zoo(Zoo t, int pos);
    void delete_from_file(int startAge, int endAge, char* name);
    int clear_file(const char* filename);
    auto create();
    ~Zoo() {}
};