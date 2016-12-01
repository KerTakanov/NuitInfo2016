int main(int argc, char const *argv[])
{
    string str = "Salut ça va ?";
    vector<string> vstr;

    boost::split(vstr, str, boost::is_any_of(" "));
    return 0;
}