/**********************************************************\

  Auto-generated CpABEAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"

#include "CpABEAPI.h"

#include <sstream>
#include <memory>
#include <cstring>
#include <fstream>

#include "Hex.hpp"
#include <boost/move/move.hpp>

#include "bswcpabe.h"

///////////////////////////////////////////////////////////////////////////////
/// @fn FB::variant CpABEAPI::echo(const FB::variant& msg)
///
/// @brief  Echos whatever is passed from Javascript.
///         Go ahead and change it. See what happens!
///////////////////////////////////////////////////////////////////////////////
FB::variant CpABEAPI::echo(const FB::variant& msg)
{
    static int n(0);
    fire_echo("So far, you clicked this many times: ", n++);

    // return "foobar";
    return msg;
} 
///////////////////////////////////////////////////////////////////////////////
/// @fn CpABEPtr CpABEAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
CpABEPtr CpABEAPI::getPlugin()
{
    CpABEPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}

// Read/Write property testString
std::string CpABEAPI::get_testString()
{
    return m_testString;
}

void CpABEAPI::set_testString(const std::string& val)
{
    m_testString = val;
}

// Read-only property version
std::string CpABEAPI::get_version()
{
    return FBSTRING_PLUGIN_VERSION;
}

void CpABEAPI::testEvent()
{
    fire_test();
}

//FB::VariantList CpABEAPI::setup()
//{
    //bswabe_pub_t *pub;
    //bswabe_msk_t *msk;
    //bswabe_setup(&pub, &msk);
    //GByteArray *p = bswabe_pub_serialize(pub);
    //GByteArray *m = bswabe_msk_serialize(msk);

    //std::vector<std::string> ret;

    //std::string pub_str = Hex::encode(std::string(reinterpret_cast<const char*>(p->data), p->len));
    //std::string msk_str = Hex::encode(std::string(reinterpret_cast<const char*>(m->data), m->len));

    //ret.push_back(boost::move(pub_str));
    //ret.push_back(boost::move(msk_str));

    //g_byte_array_free(p, 1);
    //g_byte_array_free(m, 1);
    //free(pub);
    //free(msk);
    //return FB::make_variant_list(ret);
//}

namespace {

// pub_str and msk_str is raw binary
GByteArray *do_keygen(const std::string &pub_str, const std::string &msk_str, const FB::VariantList &attrs)
{
    bswabe_pub_t *pub;
    bswabe_msk_t *msk;
    bswabe_prv_t *prv;

    GByteArray *a, *b; 
    a = g_byte_array_new();
    b = g_byte_array_new();
    g_byte_array_set_size(a, pub_str.size());
    g_byte_array_set_size(b, msk_str.size());
    std::memcpy(a->data, pub_str.data(), pub_str.size());
    std::memcpy(b->data, msk_str.data(), msk_str.size());
    pub = bswabe_pub_unserialize(a, 1);
    msk = bswabe_msk_unserialize(pub, b, 1);

    std::vector<char*> attributes;
    //for (size_t i = 0; i < attrs.size(); ++i) {
        //attributes.push_back(const_cast<char*>(attrs[i].c_str()));
    //}

    prv = bswabe_keygen(pub, msk, attributes.data());
    GByteArray *ret = bswabe_prv_serialize(prv);
    free(pub);
    free(msk);
    free(prv);
    return ret;
}

GByteArray *read_file(const char *path) {
    std::ifstream in(path, std::ios::binary);
    GByteArray *ret = NULL;
    if (in) {
        in.seekg(0, in.end);
        int len = in.tellg();
        in.seekg(0, in.beg);
        ret = g_byte_array_new();
        g_byte_array_set_size(ret, len);
        in.read(reinterpret_cast<char*>(ret->data), len);
        in.close();
    } else {
        fprintf(stderr, "Open %s failed!\n", path);
    }
    return ret;
}

std::string abe_dec(const char *pub_path, const char *prv_path, const std::string &chphertext) {
    //bswabe_pub_t *pub = bswabe_pub_unserialize(read_file(pub_path), 1);
    //bswabe_prv_t *prv = bswabe_prv_unserialize(pub, read_file(prv_path), 1);
    suck_file(const_cast<char*>(pub_path));
    
    return std::string();
}

} // Anonymous namespace

