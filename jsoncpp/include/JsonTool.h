#pragma once

#include "type.h"
#include "json/json.h"

class JsonTool {
public:
    static string dump(const Json::Value &root);

    static Json::Value parse(const string &str);

    template<typename K, typename V, typename...Args>
    inline static Json::Value createObject(const K &k, const V &v, Args...args) { return _createObject(k, v, args...); }

    template<typename X, typename...Args>
    inline static Json::Value createArray(const X &x, Args...args) { return _createArray(x, args...); }

    template<typename M>
    inline static Json::Value toObject(const M &m) { return _toObject(m); }

    template<typename A>
    inline static Json::Value toArray(const A &a) { return _toArray(a); }

    template<typename It>
    inline static Json::Value toArray(It begin, It end) { return _toArray(begin, end); }


private:
    // 为保持简洁，使用模板的方法实现放在这里，public里只透传

    template<typename K, typename V, typename...Args>
    static Json::Value _createObject(const K &k, const V &v, Args...args) {
        Json::Value root;
        root[k] = v;
        if constexpr (sizeof...(args) > 0) {
            Json::Value other = _createObject(args...);
            for (const string &key: other.getMemberNames()) {
                root[key] = other[key];
            }
        }
        return root;
    }

    template<typename X, typename...Args>
    static Json::Value _createArray(const X &x, Args...args) {
        Json::Value root;
        root.append(x);
        if constexpr (sizeof...(args) > 0) {
            Json::Value other = _createArray(args...);
            for (const Json::Value &item: other) {
                root.append(item);
            }
        }
        return root;
    }

    template<typename M>
    static Json::Value _toObject(const M &m) {
        Json::Value root;
        for (auto &[k, v]: m) {
            root[string(k)] = v;
        }
        return root;
    }

    template<typename A>
    static Json::Value _toArray(const A &a) {
        Json::Value root;
        for (auto &x: a) {
            root.append(x);
        }
        return root;
    }

    template<typename It>
    static Json::Value _toArray(It begin, It end) { //为了传数组的时候更方便，不使用const&
        Json::Value root;
        for (It it = begin; it != end; ++it) {
            root.append(*it);
        }
        return root;
    }
};
