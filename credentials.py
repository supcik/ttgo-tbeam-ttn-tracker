Import("env")

import os
try:
    from dotenv import load_dotenv
except ImportError:
    env.Execute("$PYTHONEXE -m pip install python-dotenv")
    from dotenv import load_dotenv

load_dotenv()

def append_list(defines, env_var, key, expected_len, reverse=False):
    hex_string = os.getenv(env_var, None)
    if hex_string is None:
        return

    l = list(bytes.fromhex(hex_string))
    if len(l) != expected_len:
        raise ValueError("Invalid length for {0}".format(env_var))
    
    if reverse:
        l.reverse()

    v = ", ".join(["0x{0:X}".format(i) for i in l])
    defines.append((key, v))

def append_hex(defines, env_var, key):
    hex_string = os.getenv(env_var, None)
    if hex_string is None:
        return
    v = "0x{0:X}".format(int(hex_string, 16))
    defines.append((key, v))

cpp_defines = list()

append_list(cpp_defines, "LW_APPEUI", "LW_APPEUI", 8, reverse=True)
append_list(cpp_defines, "LW_DEVEUI", "LW_DEVEUI", 8, reverse=True)
append_list(cpp_defines, "LW_APPKEY", "LW_APPKEY", 16)
append_list(cpp_defines, "LW_NWKSKEY", "LW_NWKSKEY", 16)
append_list(cpp_defines, "LW_APPSKEY", "LW_APPSKEY", 16)
append_hex(cpp_defines, "LW_DEVADDR", "LW_DEVADDR")

env.Append(CPPDEFINES=cpp_defines)