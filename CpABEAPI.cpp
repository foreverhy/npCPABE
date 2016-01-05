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

#include "Hex.hpp"
#include <boost/move/move.hpp>

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

FB::VariantList CpABEAPI::setup()
{
    bswabe_pub_t *pub;
    bswabe_msk_t *msk;
    bswabe_setup(&pub, &msk);
    GByteArray *p = bswabe_pub_serialize(pub);
    GByteArray *m = bswabe_msk_serialize(msk);

    std::vector<std::string> ret;

    std::string pub_str = Hex::encode(std::string(reinterpret_cast<const char*>(p->data), p->len));
    std::string msk_str = Hex::encode(std::string(reinterpret_cast<const char*>(m->data), m->len));

    ret.push_back(boost::move(pub_str));
    ret.push_back(boost::move(msk_str));

    g_byte_array_free(p, 1);
    g_byte_array_free(m, 1);
    free(pub);
    free(msk);
    return FB::make_variant_list(ret);
}

