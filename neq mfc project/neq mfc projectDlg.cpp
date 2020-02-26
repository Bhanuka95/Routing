
// neq mfc projectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "neq mfc project.h"
#include "neq mfc projectDlg.h"
#include "afxdialogex.h"

#include <limits.h> 
#include <iostream>
#include <string>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// Number of vertices 
// in the graph 
#define V 9 

// A utility function to find the 
// vertex with minimum distance 
// value, from the set of vertices 
// not yet included in shortest 
// path tree 

string conct(string a, int b)
{
	return a + std::to_string(b);
}


string str_1 = "0", str_2, str_3;



int minDistance(int dist[],
	bool sptSet[])
{

	// Initialize min value 
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}

	return min_index;
}

// Function to print shortest 
// path from source to j 
// using parent array 
void printPath(int parent[], int j)
{

	// Base Case : If j is source 
	if (parent[j] == -1)
		return;

	printPath(parent, parent[j]);

	cout << j;
	string temp = conct("", j);
	str_3 = str_3 + temp;
}

// A utility function to print 
// the constructed distance 
// array 


void printSolution(int dist[], int n,
	int parent[], int dst)

{
	int src = 0;

	

	cout << "Vertex\t\t Distance\t  Path";


	cout << "\n" << src << "->" << dst << "\t\t  " << dist[dst] << "\t\t  ";
	
	str_1 = str_1 + conct("->", dst);
	str_2 = conct(" ", dist[dst]);

	printPath(parent, dst);

}

// Funtion that implements Dijkstra's 
// single source shortest path 
// algorithm for a graph represented 
// using adjacency matrix representation 
void dijkstra(int graph[V][V], int src, int dst)
{

	// The output array. dist[i] 
	// will hold the shortest 
	// distance from src to i 
	int dist[V];

	// sptSet[i] will true if vertex 
	// i is included / in shortest 
	// path tree or shortest distance 
	// from src to i is finalized 
	bool sptSet[V];

	// Parent array to store 
	// shortest path tree 
	int parent[V];

	// Initialize all distances as 
	// INFINITE and stpSet[] as false 

	for (int i = 0; i < V; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// Distance of source vertex 
	// from itself is always 0 
	dist[src] = 0;

	// Find shortest path 
	// for all vertices 
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum distance 
		// vertex from the set of 
		// vertices not yet processed. 
		// u is always equal to src 
		// in first iteration. 
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex 
		// as processed 
		sptSet[u] = true;

		// Update dist value of the 
		// adjacent vertices of the 
		// picked vertex. 
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is 
			// not in sptSet, there is 
			// an edge from u to v, and 
			// total weight of path from 
			// src to v through u is smaller 
			// than current value of 
			// dist[v] 
			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	// print the constructed 
	// distance array 
	printSolution(dist, V, parent, dst);
}


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CneqmfcprojectDlg dialog



CneqmfcprojectDlg::CneqmfcprojectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NEQMFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CneqmfcprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CneqmfcprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(Btn1, &CneqmfcprojectDlg::OnBnClickedBtn1)
	ON_BN_CLICKED(Btn2, &CneqmfcprojectDlg::OnBnClickedBtn2)
END_MESSAGE_MAP()


// CneqmfcprojectDlg message handlers

BOOL CneqmfcprojectDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CneqmfcprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CneqmfcprojectDlg::OnPaint()
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
HCURSOR CneqmfcprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int graph[V][V] = {
	{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
};



int Destination;
void CneqmfcprojectDlg::OnBnClickedBtn1()
{
	CString input;
	GetDlgItemText(Dest, input);
	Destination = _ttoi(input);

	CString vrtx(str_1.c_str());
	CString distance(str_2.c_str());
	CString pth(str_3.c_str());

	SetDlgItemText(Vertex1, vrtx);
	SetDlgItemText(Dist1, distance);
	SetDlgItemText(Path1, pth);



	//cout << "Your light path details\n";
	dijkstra(graph, 0, Destination);

	
}




void CneqmfcprojectDlg::OnBnClickedBtn2()
{
	str_1.clear();
	str_2.clear();
	str_3.clear();
	str_1 = "0 ";
	// TODO: Add your control notification handler code here
	CString input;

	GetDlgItemText(T1, input);
	int trouble_1 = _ttoi(input);
	GetDlgItemText(T2, input);
	int trouble_2 = _ttoi(input);

	graph[trouble_1][trouble_2] = 0;

	dijkstra(graph, 0, Destination);

	CString vrtx(str_1.c_str());
	CString distance(str_2.c_str());
	CString pth(str_3.c_str());

	

	SetDlgItemText(V2, vrtx);
	SetDlgItemText(D2, distance);
	SetDlgItemText(P2, pth);
}
