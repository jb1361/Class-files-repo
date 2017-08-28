#pragma once
#include <shobjidl.h> 

// Common File Dialog - wrapper for Windows common file dialog box
// Date: 8/16
// Author: Dr. Holly

class CommonFileDialog
{
public: // Standard Operations
	CommonFileDialog();
	~CommonFileDialog();
	void clear(void);
	void transferFrom(CommonFileDialog& source);
	CommonFileDialog& operator = (CommonFileDialog& rhs);

	// CommonFileDialog Specific Operations
	void getOpenFilename(Text& fullPathName, Text& fileNameOnly, Boolean& successful);
	//! replaces fullPathName, fileNameOnly, successful

	void getSaveDataFilename(Text& fullPathName, Text& fileNameOnly, Boolean& successful);
	//! replaces fullPathName, fileNameOnly, successful


private: // Representation

	// Disallowed CommonFileDialog Operations
	CommonFileDialog(const CommonFileDialog& s);
	CommonFileDialog* operator & (void) { return (this); };
	const CommonFileDialog* operator & (void) const { return (this); };

};	// end CommonFileDialog


//-----------------------------------------------------------------------
// Exported Operations
//-----------------------------------------------------------------------

CommonFileDialog::CommonFileDialog()
{
}	// CommonFileDialog

//-----------------------------------------------------------------------

CommonFileDialog::~CommonFileDialog()
{
}	// ~CommonFileDialog

//-----------------------------------------------------------------------

void CommonFileDialog::transferFrom(CommonFileDialog& source)
{
} // transferFrom

//-----------------------------------------------------------------------

CommonFileDialog&
CommonFileDialog::operator = (CommonFileDialog& rhs)
{
	return (*this);
} // operator =

//-----------------------------------------------------------------------

void CommonFileDialog::clear(void)
{
}	// clear

//-----------------------------------------------------------------------
void CommonFileDialog::getOpenFilename(
		Text& fullPathName,
		Text& fileNameOnly,
		Boolean& successful
	)
{
	fullPathName.clear();
	fileNameOnly.clear();

	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
	if (SUCCEEDED(hr)) {
		IFileOpenDialog *pFileOpen;

		// Create the FileOpenDialog object.
		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL, IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));
		
		if (SUCCEEDED(hr)) {
			// Show the Open dialog box.
			hr = pFileOpen->Show(NULL);

			// Get the file name from the dialog box.
			if (SUCCEEDED(hr)) {
				IShellItem *pItem;
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr)) {
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);
					if (SUCCEEDED(hr)) {
						fullPathName = pszFilePath;
						CoTaskMemFree(pszFilePath);
						hr = pItem->GetDisplayName(SIGDN_NORMALDISPLAY, &pszFilePath);
						if (SUCCEEDED(hr)) {
							fileNameOnly = pszFilePath;
							CoTaskMemFree(pszFilePath);
						} // end if
					} // end if
					pItem->Release();
				} // end if
			} // end if
			pFileOpen->Release();
		} // end if
		CoUninitialize();
	} // end if
	successful = (fullPathName.size() != 0) && (fileNameOnly.size() != 0);
}	// getOpenFilename

//-----------------------------------------------------------------------

void CommonFileDialog::getSaveDataFilename(
	Text& fullPathName,
	Text& fileNameOnly,
	Boolean& successful
	)
{
	/*
		// CoCreate the File Open Dialog object.
		IFileDialog *pfd = NULL;
		HRESULT hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pfd));
		if (SUCCEEDED(hr))
		{
			// Create an event handling object, and hook it up to the dialog.
			IFileDialogEvents *pfde = NULL;
			hr = CDialogEventHandler_CreateInstance(IID_PPV_ARGS(&pfde));
			if (SUCCEEDED(hr))
			{
				// Hook up the event handler.
				DWORD dwCookie;
				hr = pfd->Advise(pfde, &dwCookie);
				if (SUCCEEDED(hr))
				{
					// Set the options on the dialog.
					DWORD dwFlags;

					// Before setting, always get the options first in order 
					// not to override existing options.
					hr = pfd->GetOptions(&dwFlags);
					if (SUCCEEDED(hr))
					{
						// In this case, get shell items only for file system items.
						hr = pfd->SetOptions(dwFlags | FOS_FORCEFILESYSTEM);
						if (SUCCEEDED(hr))
						{
							// Set the file types to display only. 
							// Notice that this is a 1-based array.
							hr = pfd->SetFileTypes(ARRAYSIZE(c_rgSaveTypes), c_rgSaveTypes);
							if (SUCCEEDED(hr))
							{
								// Set the selected file type index to Word Docs for this example.
								hr = pfd->SetFileTypeIndex(INDEX_WORDDOC);
								if (SUCCEEDED(hr))
								{
									// Set the default extension to be ".doc" file.
									hr = pfd->SetDefaultExtension(L"doc;docx");
									if (SUCCEEDED(hr))
									{
										// Show the dialog
										hr = pfd->Show(NULL);
										if (SUCCEEDED(hr))
										{
											// Obtain the result once the user clicks 
											// the 'Open' button.
											// The result is an IShellItem object.
											IShellItem *psiResult;
											hr = pfd->GetResult(&psiResult);
											if (SUCCEEDED(hr))
											{
												// We are just going to print out the 
												// name of the file for sample sake.
												PWSTR pszFilePath = NULL;
												hr = psiResult->GetDisplayName(SIGDN_FILESYSPATH,
													&pszFilePath);
												if (SUCCEEDED(hr))
												{
													TaskDialog(NULL,
														NULL,
														L"CommonFileDialogApp",
														pszFilePath,
														NULL,
														TDCBF_OK_BUTTON,
														TD_INFORMATION_ICON,
														NULL);
													CoTaskMemFree(pszFilePath);
												}
												psiResult->Release();
											}
										}
									}
								}
							}
						}
					}
					// Unhook the event handler.
					pfd->Unadvise(dwCookie);
				}
				pfde->Release();
			}
			pfd->Release();
		}
		return hr;
		*/
}	// getSaveDataFilename

