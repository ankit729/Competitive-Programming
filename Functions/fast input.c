#define gc getchar_unlocked
void scan(int& ret){
    char c=gc();
    while(c<'0' || c>'9')
        c=gc();
    ret=0;
    while(c>='0' && c<='9'){
        ret=ret*10+c-48;
        c=gc();
    }
}
