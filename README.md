http://codelite.org/LiteEditor/WxWidgets30Binaries#toc2

```
sudo apt-add-repository 'deb http://repos.codelite.org/wx3.0.2/ubuntu/ trusty universe'
apt-get update
apt-get install libwxbase3.0-0-unofficial \
			libwxbase3.0-dev \
			libwxgtk3.0-0-unofficial \
			libwxgtk3.0-dev \
			wx3.0-headers \
			wx-common \
			libwxbase3.0-dbg \
			libwxgtk3.0-dbg \
			wx3.0-i18n \
			wx3.0-examples \
			wx3.0-doc

g++ main.cpp `wx-config --cxxflags --libs` -o app
```