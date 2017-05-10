#include <Windows.h>
#include "resource.h"

HWND hWnd;
LRESULT CALLBACK DlgProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN), hWnd, reinterpret_cast<DLGPROC>(DlgProc));

	return FALSE;
}

LRESULT CALLBACK DlgProc(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg) {
		case WM_INITDIALOG:
			return TRUE;

		case WM_COMMAND:
			switch (wParam) {
				case IDCANCEL:
				case IDOK:
					EndDialog(hWndDlg, 0);
					return TRUE;
				case IDC_BROWSE:
					MessageBox(hWndDlg, L"Hello World!", L"Icon Extractor", MB_OK);
					return FALSE;
			}
		break;
	}

	return FALSE;
}