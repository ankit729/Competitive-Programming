void scan(int &number){
    bool negative=false;
    register int c;
    number=0;
    c=getchar_unlocked();
    if(c=='-'){
        negative=true;
        c=getchar_unlocked();
    }
    for(;(c>47 && c<58);c=getchar_unlocked())
        number=number*10+c-48;
    if(negative)
        number=-number;
}
ios_base::sync_with_stdio(false);cin.tie(NULL);
