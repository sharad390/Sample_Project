
// SampleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Sample.h"
#include "SampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSampleDlg dialog



CSampleDlg::CSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSampleDlg::IDD, pParent)
	, m_number(_T(""))
	, m_hobbies(_T(""))
	, m_language(_T(""))
	, m_search(_T(""))
	, m_male(0)
	, m_female(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_number);
	DDX_Text(pDX, IDC_EDIT2, m_strName);
	DDX_Text(pDX, IDC_EDIT4, m_hobbies);
	DDX_CBString(pDX, IDC_COMBO1, m_language);
	DDX_Text(pDX, IDC_EDIT5, m_search);
	DDX_Control(pDX, IDC_COMBO1, m_combobox);


	DDX_Control(pDX, IDC_LIST7, m_lstIDC_LIST1Control);
}

BEGIN_MESSAGE_MAP(CSampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CSampleDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT4, &CSampleDlg::OnEnChangeEdit4)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSampleDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CSampleDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CSampleDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CSampleDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CSampleDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CSampleDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CSampleDlg message handlers

BOOL CSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_lstIDC_LIST1Control.SetExtendedStyle( LVS_EX_FULLROWSELECT );
	m_lstIDC_LIST1Control.InsertColumn(0, _T("Personal Number"), LVCFMT_LEFT, 70);
	m_lstIDC_LIST1Control.InsertColumn(1, _T("Name"), LVCFMT_LEFT, 90);
	m_lstIDC_LIST1Control.InsertColumn(2, _T("Gender"), LVCFMT_LEFT, 30);
	m_lstIDC_LIST1Control.InsertColumn(3, _T("Familier Language"), LVCFMT_LEFT, 50);
	m_lstIDC_LIST1Control.InsertColumn(4, _T("Hobbies"), LVCFMT_LEFT, 120);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSampleDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	AfxMessageBox(L"Hello world");
	CDialogEx::OnOK();
}


void CSampleDlg::OnEnChangeEdit4()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.


	// TODO:  Add your control notification handler code here
}


void CSampleDlg::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}


void CSampleDlg::OnBnClickedButton1()
{
	// Add records in List Control
	
	UpdateData(true);

	int index =	m_lstIDC_LIST1Control.GetItemCount();
	if(index != 0)
		index++;

	int nIndex = m_lstIDC_LIST1Control.InsertItem(index, m_number.GetString());
	m_lstIDC_LIST1Control.SetItemText(nIndex, 1, m_strName.GetString());
	
	int choice = GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO2);
	

	if(choice == IDC_RADIO1)
		m_lstIDC_LIST1Control.SetItemText(nIndex, 2, L"Male");
	else
		m_lstIDC_LIST1Control.SetItemText(nIndex, 2, L"Female");

	int cur = m_combobox.GetCurSel();
	if(cur == 0)
		m_lstIDC_LIST1Control.SetItemText(nIndex, 3, L"C#");
	else if(cur == 1)
		m_lstIDC_LIST1Control.SetItemText(nIndex, 3, L"C:/C++");
	else if(cur == 2)
		m_lstIDC_LIST1Control.SetItemText(nIndex, 3, L"Delphi");
	else if(cur == 3)
		m_lstIDC_LIST1Control.SetItemText(nIndex, 3, L"VB");
	
	m_lstIDC_LIST1Control.SetItemText(nIndex, 4, m_hobbies.GetString());

	AfxMessageBox(L"Data added successfuly");

	m_number.SetString(L"");
	m_strName.SetString(L"");
	m_hobbies.SetString(L"");
	m_combobox.Clear();
	m_combobox.SetCurSel(0);
	m_male = 0;
	m_female = 0;
	m_search.SetString(L"");

	UpdateData(false);
	
}


void CSampleDlg::OnBnClickedButton4()
{
	// Save File

	int count =	m_lstIDC_LIST1Control.GetItemCount();

	if(count < 1)
	{
		AfxMessageBox(L"No records Found to Save File");
		return;
	}
		

	CStdioFile file( _T("PersonalInformation.txt"), CFile::modeCreate | CFile::modeWrite);

	file.WriteString(L"Number");
	file.WriteString(_T("     "));
	file.WriteString(L"Name  ");
	file.WriteString(_T("     "));
	file.WriteString(L"Gender ");
	file.WriteString(_T("     "));
	file.WriteString(L"Languages");
	file.WriteString(_T("     "));
	file.WriteString(L"Hobbies");
	file.WriteString(_T("     "));
	
	file.WriteString(_T("\n"));
	file.WriteString(_T("\n"));
	  
	for( int i = 0; i < count; i++)
	{
		for( int j = 0; j < 5; j++)
		{
			if( j != 0)
				file.WriteString(_T(",     "));
				
			file.WriteString( m_lstIDC_LIST1Control.GetItemText(i, j));
		}
			
		file.WriteString(_T("\n"));
		file.WriteString(_T("\n"));
	}
	
	AfxMessageBox(L"PersonalInformation.txt	File Save Successfully at Application Folder");
}


void CSampleDlg::OnBnClickedButton3()
{
	// Delete item
	int count =	m_lstIDC_LIST1Control.GetItemCount();

	if(count < 1)
	{
		AfxMessageBox(L"No records Found to Delete Item");
		return;
	}
	POSITION pos = m_lstIDC_LIST1Control.GetFirstSelectedItemPosition();
	 int selected=-1;
	 if (pos != NULL)
		{
			while (pos)
			   {
				int nItem = m_lstIDC_LIST1Control.GetNextSelectedItem(pos);
				selected = nItem;
			   }
	 }
	
	 m_lstIDC_LIST1Control.DeleteItem(selected);

	UpdateData(false);
	AfxMessageBox(L"Delete successfull");
}


void CSampleDlg::OnBnClickedButton2()
{
	// Edit Data

	int count =	m_lstIDC_LIST1Control.GetItemCount();

	if(count < 1)
	{
		AfxMessageBox(L"No records Found to Edit Item");
		return;
	}
	POSITION pos = m_lstIDC_LIST1Control.GetFirstSelectedItemPosition();
	 int selected=-1;
	 if (pos != NULL)
		{
			while (pos)
			   {
				int nItem = m_lstIDC_LIST1Control.GetNextSelectedItem(pos);
				selected = nItem;
			   }
	 }

	 if(selected == -1)
		 AfxMessageBox(L"Invalid Index Selection");
	 else
	 {
		 m_number.SetString(m_lstIDC_LIST1Control.GetItemText(selected, 0));
		 m_strName.SetString(m_lstIDC_LIST1Control.GetItemText(selected, 1));

		 CString strGender = m_lstIDC_LIST1Control.GetItemText(selected, 2);

		 if(strGender == L"Male")
		 {
			 m_male = 1;
			 m_female = 0;
			 UpdateData(false);
		 }
		 else
		 {
			 m_female = 1;
			 m_male = 0;
			 UpdateData(false);
		 }

		CString strlang = m_lstIDC_LIST1Control.GetItemText(selected, 3);
		if(strlang == L"C#")
			m_combobox.SetCurSel(0);
		else if(strlang == L"C:/C++")
			m_combobox.SetCurSel(1);
		else if(strlang == L"Delphi")
			m_combobox.SetCurSel(2);
		else 
			m_combobox.SetCurSel(3);

		m_hobbies.SetString(m_lstIDC_LIST1Control.GetItemText(selected, 4));
		 
		m_lstIDC_LIST1Control.DeleteItem(selected);
		m_search.SetString(L"");
		UpdateData(false);
	 }

	 
}


void CSampleDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int count =	m_lstIDC_LIST1Control.GetItemCount();

	if(count < 1)
	{
		AfxMessageBox(L"Record is Empty");
		return;
	}

	bool bFound = false;
	int index = -1;
	CString strKeyWord = m_search.GetString();
	for( int i = 0; i < count; i++)
	{
		for( int j = 0; j < 5; j++)
		{
			CString name = m_lstIDC_LIST1Control.GetItemText(i, j);
			if(strKeyWord == name)
			{
				index = j;
				bFound = true;
				break;
			}
		}

		if(bFound)
			break;
	}

	if(bFound)
	{
		m_lstIDC_LIST1Control.SetItemState(index-1, LVIS_SELECTED, LVIS_SELECTED);
		UpdateData(false);
		AfxMessageBox(L"Record Found : Highlighted In Table ");
	}
	else
	{
		AfxMessageBox(L"Record Not exist : ");
	}


}
