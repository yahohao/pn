#ifndef optionsdialogs_h__included
#define optionsdialogs_h__included

class CToolEditorDialog : public CDialogImpl<CToolEditorDialog>,
							public CWinDataExchange<CToolEditorDialog>
{
	public:
		CToolEditorDialog();
        
		enum {IDD = IDD_TOOLEDITOR};

		BEGIN_MSG_MAP(CToolEditorDialog)
			MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
			COMMAND_ID_HANDLER(IDOK, OnOK)
			COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
			COMMAND_ID_HANDLER(IDC_TE_COMMANDBUTTON, OnBrowseCommand);
			COMMAND_ID_HANDLER(IDC_TE_DIRBUTTON, OnBrowseDir);
		END_MSG_MAP()

		BEGIN_DDX_MAP(CToolEditorDialog)
			DDX_TEXT(IDC_TE_NAMEEDIT,		m_csName)
			DDX_TEXT(IDC_TE_CMDEDIT,		m_csCommand)
			DDX_TEXT(IDC_TE_FOLDEREDIT,		m_csFolder)
			DDX_TEXT(IDC_TE_PARAMSEDIT,		m_csParams)
			DDX_TEXT(IDC_TE_SHORTCUTEDIT,	m_csShortcut)
			DDX_CHECK(IDC_TE_CAPTURECHECK,	m_bCapture)
			DDX_CHECK(IDC_TE_FILTERCHECK,	m_bFilter)
			DDX_CHECK(IDC_TE_SAVEALLCHECK,	m_bSaveAll)
		END_DDX_MAP()

		CString m_csDisplayTitle;

		void GetValues(SToolDefinition* pDefinition);
		void SetValues(SToolDefinition* pDefinition);

		void SetTitle(LPCTSTR title);

	protected:
		class CInfoLabel : public CWindowImpl<CInfoLabel>
		{
			public:
				CInfoLabel();
				~CInfoLabel();

				BEGIN_MSG_MAP(CInfoLabel)
					MESSAGE_HANDLER(WM_PAINT, OnPaint);
				END_MSG_MAP()

			protected:
				void MakeFonts(HDC hDC);
				LRESULT OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

				CFont*	m_pTitleFont;
				TCHAR	strbuf[200];
		};

	protected:
		LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
		LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
		LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
		LRESULT OnBrowseDir(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
		LRESULT OnBrowseCommand(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	protected:
		CString	m_csName;
		CString	m_csCommand;
		CString	m_csFolder;
		CString	m_csParams;
		CString	m_csShortcut;

		BOOL	m_bCapture;
		BOOL	m_bFilter;
		BOOL	m_bSaveAll;

		CInfoLabel m_infolabel;
};

// pre-declare SchemeConfig.
class SchemeConfigParser;

class CSmartStartEditorDialog : public CDialogImpl<CSmartStartEditorDialog>
{
	public:
		CSmartStartEditorDialog(SchemeConfigParser* pSchemes);

		enum {IDD = IDD_SMARTSTARTEDITOR};

		BEGIN_MSG_MAP(CSmartStartEditorDialog)
			MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
			COMMAND_ID_HANDLER(IDOK, OnOK)
			COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
		END_MSG_MAP()

		void GetValues(tstring& startPhrase, tstring& schemeName);
		void SetValues(LPCTSTR startPhrase, LPCTSTR schemeName);

	protected:
		LRESULT OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
		LRESULT OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
		LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

	protected:
		SchemeConfigParser*	m_pSchemes;
		tstring				m_startPhrase;
		tstring				m_schemeName;
};

#endif