// TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

// Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.

class Solution {
    unordered_map<string,string> lToS,sToL;
    string siteUrl="bit.ly/";
    string possible="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(lToS.count(longUrl))
            return lToS[longUrl];
        string ans;
        do{
            ans="";
            for(int i=0;i<7;++i)
                ans+=possible[rand()%62];
        }while(sToL.count(ans));
        sToL[ans]=longUrl;
        lToS[longUrl]=ans;
        return siteUrl+ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return sToL[shortUrl.substr(siteUrl.length())];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
