struct Error {
  template <class T1, class T2> Error& operator << (pair<T1,T2> arg) {
    return *this << "(" << arg.first << ", " << arg.second << ")";
  }
  template <class T> typename enable_if<is_scalar<T>::value || is_same<T, string>::value, Error&>::type operator << (T arg) {
    cerr << boolalpha << arg;
    return *this;
  }
  template <class T> typename enable_if<!is_scalar<T>::value && !is_same<T, string>::value, Error&>::type operator << (T arg) {
    *this << "{";
    for (auto it = arg.begin(); it != arg.end(); it++) {
      if (it != arg.begin())
        *this << ", ";
      *this << *it;
    }
    return *this << "}";
  }
  template <class T1, class T2, class T3> Error& operator << (tuple <T1, T2, T3> arg) {
    return *this << "(" << get<0>(arg) << ", " << get<1>(arg) << ", " << get<2>(arg) << ")";
  }
  template <class T1, class T2, class T3, class T4> Error& operator << (tuple <T1, T2, T3, T4> arg) {
    return *this << "(" << get<0>(arg) << ", " << get<1>(arg) << ", " << get<2>(arg) << ", " << get<3>(arg) << ")";
  }
  template <class T> Error& operator << (queue <T> arg) {
    vector <T> res;
    while (!arg.empty()) {
      res.push_back(arg.front());
      arg.pop();
    }
    return *this << res;
  }
  template <class T> Error& operator << (stack <T> arg) {
    vector <T> res;
    while (!arg.empty()) {
      res.push_back(arg.top());
      arg.pop();
    }
    return *this << res;
  }
};

#define err Error()

template <class T> void dout(string name, T arg) {
  err << name << " : " << arg << "\n";
}

template <class T1, class... T2> void dout(string names, T1 arg, T2... args) {
  err << names.substr(0, names.find(",")) << " : " << arg << " | ";
  dout(names.substr(names.find(",") + 2), args...);
}

#ifdef LOCAL
#define debug(...) dout(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
