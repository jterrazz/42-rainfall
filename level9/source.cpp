class N {
    private:
        char    _str[100];
        int     _nb; = 5
    public:
        operator-(N& obj)   {
            _nb -= obj._nb
        }
        operator+(N& obj)   {
            _nb += obj._nb
        }
        N(int nb)   { 
            _nb = nb; 
        } 
        setAnnotation(char* str)    {
            memcpy(_str, str, strlen(str));
        }
}

int main(int ac, char **av) {
    if (ac <= 1)
        exit(1);
    N& obj1 = new N(5);
    N& obj2 = new N(6);
    obj1.setAnnotation(av[1]);
    obj2._str();
    return (0);
}