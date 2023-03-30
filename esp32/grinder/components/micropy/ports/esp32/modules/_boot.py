import gc
import uos
from flashbdev import bdev

def wlan_connect(ssid='Zimplistic', password='Zimplistic123'):
    import network
    wlan = network.WLAN(network.STA_IF)
    if not wlan.active() or not wlan.isconnected():
        wlan.active(True)
        print('connecting to:', ssid)
        wlan.connect(ssid, password)
        while not wlan.isconnected():
            pass
    print('network config:', wlan.ifconfig())

try:
    if bdev:
        uos.mount(bdev, "/")
except OSError:
    import inisetup
    vfs = inisetup.setup()
    
    
wlan_connect()
import webrepl
webrepl.start(password='123456')

gc.collect()
