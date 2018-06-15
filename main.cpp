#define STRICT
#define NOCRYPT

#include <windows.h>
#include <Shlobj.h>
#include <tchar.h>
#include <assert.h>

/*
https://msdn.microsoft.com/en-us/library/windows/desktop/bb762153(v=vs.85).aspx
*/

const TCHAR szOperation[] = _T("open");
const TCHAR szAddress[] = _T("www.google.com");

const TCHAR szFolder[] = _T("C:\\Users\\");


void ShellOpen(LPCTSTR filename) {
    HINSTANCE hRslt = ShellExecute(NULL, szOperation, filename, NULL, NULL, SW_SHOWNORMAL);

    assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}

void BrowseToFile(LPCTSTR filename)
{
    ITEMIDLIST *pidl = ILCreateFromPath(filename);
    if (pidl) {
        SHOpenFolderAndSelectItems(pidl, 0, 0, 0);
        ILFree(pidl);
    }
}




int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR lpCmd, int nShow) {
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

    // BrowseToFile(szFolder);
    ShellOpen(szFolder);

    CoUninitialize();
    return 0;
}
