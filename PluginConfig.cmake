#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for CpABEPlugin
#
#\**********************************************************/

set(PLUGIN_NAME "CpABE")
set(PLUGIN_PREFIX "ABE")
set(COMPANY_NAME "verihy")

# ActiveX constants:
set(FBTYPELIB_NAME CpABELib)
set(FBTYPELIB_DESC "CpABE 1.0 Type Library")
set(IFBControl_DESC "CpABE Control Interface")
set(FBControl_DESC "CpABE Control Class")
set(IFBComJavascriptObject_DESC "CpABE IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "CpABE ComJavascriptObject Class")
set(IFBComEventSource_DESC "CpABE IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID b63623cc-157d-5f3a-bc19-a6a51ce84b4f)
set(IFBControl_GUID b26adc12-72fc-5afc-95f9-d83c699cb3f4)
set(FBControl_GUID e967c45d-e9d9-5bd8-a200-1aa8e939c932)
set(IFBComJavascriptObject_GUID f3923bad-4973-5b42-b65a-17c4816e3d41)
set(FBComJavascriptObject_GUID 994c816a-2fdd-544f-b2e8-7dfc97e5ae47)
set(IFBComEventSource_GUID a3a1a0ab-9736-55cb-8338-c5fdd6b07c86)
if ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID 38a9ed8b-ac0e-559e-b17c-f9ff9b2fa210)
else ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID 9c3545bd-4faa-5bf3-96ea-f45f0702f160)
endif ( FB_PLATFORM_ARCH_32 )

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "verihy.CpABE")
if ( FB_PLATFORM_ARCH_32 )
    set(MOZILLA_PLUGINID "verihy.me/CpABE")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(MOZILLA_PLUGINID "verihy.me/CpABE_${FB_PLATFORM_ARCH_NAME}")
endif ( FB_PLATFORM_ARCH_32 )

# strings
set(FBSTRING_CompanyName "verihy")
set(FBSTRING_PluginDescription "cpabe wrapper")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2016 verihy")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}")
if (APPLE)
    # On apple, np is not needed
    set(FBSTRING_PluginFileName "${PLUGIN_NAME}")
endif()
set(FBSTRING_ProductName "CpABEPlugin")
set(FBSTRING_FileExtents "")
if ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "CpABEPlugin")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "CpABEPlugin_${FB_PLATFORM_ARCH_NAME}")
endif ( FB_PLATFORM_ARCH_32 )
set(FBSTRING_MIMEType "application/x-cpabe")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 0)
set(FBMAC_USE_COCOA 0)
set(FBMAC_USE_COREGRAPHICS 0)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
