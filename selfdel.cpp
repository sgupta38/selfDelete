/** @file selfdel.cpp
*   @brief Application which deletes itself.
*
*   @author Sonu Gupta
*/

#include <windows.h>
#include <iostream>
#include <TCHAR.h>
using namespace std;

BOOL SelfDelete()
{
  TCHAR szFile[MAX_PATH];
  TCHAR szCmd[MAX_PATH];

  if(
  (GetModuleFileName(0, szFile, MAX_PATH)!=0)
  &&
  (GetShortPathName(szFile ,szFile, MAX_PATH)!=0)
  )
  {
    lstrcpy(szCmd, _T("/c del "));
    lstrcat(szCmd, szFile);
    lstrcat(szCmd, _T(" >> NUL"));

    if(
    (GetEnvironmentVariable(_T("ComSpec"), szFile, MAX_PATH) != 0)
    &&
    ((INT)ShellExecute(0, 0, szFile, szCmd, 0, SW_HIDE) > 32)
    )
      return TRUE;
  }
  return FALSE;
}

int main()
{
  BOOL boRet;

  boRet = SelfDelete();
  if (FALSE == boRet)
    cout << "Internal Error Occured.";
  return 0;
}