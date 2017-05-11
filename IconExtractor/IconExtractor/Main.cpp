#include <Windows.h>
#include <commdlg.h>
#include "resource.h"

HWND hWnd;
LRESULT CALLBACK DlgProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
void BrowseFile(HWND parent, HWND text);
void BrowseFolder(HWND parent, HWND text);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), hWnd, reinterpret_cast<DLGPROC>(DlgProc));

	return FALSE;
}

LRESULT CALLBACK DlgProc(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT retval = false;
	switch (Msg) {
		case WM_INITDIALOG:
			retval = true;
			break;
		case WM_COMMAND:
			switch (wParam) {
				case IDCANCEL:
				case IDOK:
					EndDialog(hWndDlg, 0);
					retval = true;
					break;
				case IDC_BROWSE:
					BrowseFolder(hWndDlg, GetDlgItem(hWndDlg, IDC_FILENAME));
					break;
				case IDC_BROWSE2:
					BrowseFile(hWndDlg, GetDlgItem(hWndDlg, IDC_FILENAME2));
					break;
			}
			break;
	}

	return retval;
}

void BrowseFile(HWND parent, HWND text)
{
	OPENFILENAME ofn;
	TCHAR szFile[260];
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = parent;
	ofn.lpstrFile = szFile;
	GetWindowText(text, szFile, sizeof(szFile));
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = L"All\0*.EXE;*.DLL\0Executables\0*.EXE\0DLLs\0*.DLL\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = nullptr;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = nullptr;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	if (GetOpenFileName(&ofn) == true) {
		SetWindowText(text, szFile);
	}
}

void BrowseFolder(HWND parent, HWND text)
{
}
