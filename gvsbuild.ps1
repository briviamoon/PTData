mkdir C:\gtk-build\github
cd C:\gtk-build\github
git clone https://github.com/wingtk/gvsbuild.git
cd C:\gtk-build\github\gvsbuild
python -m venv .venv
.\.venv\Scripts\activate.ps1
pip install .

gvsbuild build gtk3 'C:\Program Files (x86)\Microsoft Visual Studio\2022\Community'
