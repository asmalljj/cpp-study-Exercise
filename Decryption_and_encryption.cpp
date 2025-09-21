#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string x = "B!ofx!jowfstf!ifbu!dpoevdujpo!gsbnfxpsl!gps!4E!jnbhjoh!sfdpotusvdujpo!jt!qspqptfe!jo!uijt!qbqfs/!Gjstu-!uif!cbtjd!jefb!up!vtf!uif!JID!gps!4E!ebnbhf!jnbhjoh!jt!ejtdvttfe!boe!gpsnvmbufe/Uif!qspqptfe!JID!jodmveft!uisff!nbkps!dpnqpofout;!gpsxbse!uifsnbm!bobmztjt!tpmwfs-!bekpjou!nfuipe!gps!fggjdjfou!tfotjujwjuz!bobmztjt-!boe!dpokvhbuf!hsbejfou!nfuipe!xjui!dpotusbjout/!Gpmmpxjoh!uijt-!uif!qspqptfe!JID!gsbnfxpsl!jt!bqqmjfe!up!b!tjnqmf!pof!ejnfotjpobm!qspcmfn!up!jmmvtusbuf!uif!lfz!tufqt/!Ofyu-!uxp!bqqmjdbujpo!fybnqmft!jo!4E!bsf!jowftujhbufe/!Tqfdjbm!gpdvtft!po!uif!efufdubbjmjuz-!dpowfshfodf-!boe!spcvtuoftt!bsf!ejtdvttfe!jo!efubjm/!Gjobmmz-!tfwfsbm!dpodmvtjpot!boe!gvuvsf!xpsl!bsf!esbxo!cbtfe!po!uif!qspqptfe!tuvez!boe!ovnfsjdbm!sftvmut/";

string decrypt_simple(const string& s) {
    string res;
    for(char c : s) res += char(c - 1);
    return res;
}
string encrypt_strong(const string& s) {
    string res;
    for(char c : s) res += char(c + 3);
    reverse(res.begin(), res.end());
    return res;
}

string decrypt_strong(const string& s) {
    string temp = s;
    reverse(temp.begin(), temp.end());
    string res;
    for(char c : temp) res += char(c - 3);
    return res;
}

int main() {

    string plain = decrypt_simple(x);
    cout << "解密后的英文段落：" << endl << plain << endl << endl;

    string strong_x = encrypt_strong(plain);
    cout << "强加密后的英文段落：" << endl << strong_x << endl << endl;

    string strong_plain = decrypt_strong(strong_x);
    cout << "强加密解密后的英文段落：" << endl << strong_plain << endl;

    return 0;
}