# mfcExam

List of what I did : 
https://www.youtube.com/watch?v=hdc4BahGsr4&list=PLlIX4lkC1JdMx-vfK8I-J3-L-GL7TbMf9&index=6 

github 
github desktop 
	create a new repository on your hard disk. 
	
	C:\Project\ mfc Exam 
	OpenVisual studio 2015 make Project 
	
	Make solution 
		gSolution 
		gProject
		
		1 Solution can have several Projects
			Server-client 
			--> Project Server 
			--> Project Client 
		
		move created Solution into git folder 
	open in visual studio 2015 
	
	changes :
	hard disk sync with cloud 
	some file does not need: 
		some file continuous generate 
		--> not sync --> delete : 
		
		Github: 
		repository -> repository setting 
		-> ignored files 
		
		publish repository to github 
		
		build project 
		
		add ignor x64/ 
		add ignore ipch/ 
		
		add function 
		--> check to main 
			
		test: delete folder mfcexam 
		then clone again 
		
		Dialog already done 
		
		Add Class: 
			Project -> Add class 
			--> MFC class ... 
			Base class: CDialogEx
			CDlgImage
			
			--> can see in resource 1 more dialog
		
		add static text to IDD_DLGIMAGE
		
		From gProjectDlg --> make button: 
		when press --> make an object of DlgImage
			this object call DoModal 
			-> create the new one 
		
		make relation between each dialog: 
		From Main class, init a object 
		Create : mpDlgImage->Create(IDD_DLGIMAGE, this) 
		to make that one 
		then show it. 
		
		move ShowWindow into function onBnClickBtnDlg
		-> when click it, it will show the window
		
		about new object created, make destroy function to remove it 
			add WM_DESTROY 
			
		Connect parent and child dialog 
		put Object DlImage to h file 
		
		make a button in DLGIMAGE 
			this button will call parent 
			put a pointer to parent CWnd * m_pParent 
			int header file of DLGIMAGE 
				assign pointer to parent.
				
			in cpp file, function click btn 
			make pointer point to parent 
			this pointer call: CallFunc 
			to make Parent do something 
			
			get Parent value and assign to variable in dialog 
			
		
		from child dialog DLGIMAGE 
		go to parent dialog
			 	
		to debug : use mfc console 
		add to debug 
		main object: 
		#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

		in main dialog class gProjectDlg.cpp
		test function to get data 
		
		static int variable --> init one and will continues change 
		work as global. 
		
		test: press button parent in child dialog 
		-> this function will call pointer to parent. 
		put variable from child to parent pointer 
		parent pointer call function in parent: 
			print out value from child 
		
		commit to main -> push Origin 
		
4.4 		
Dual Image Dialog Insert 
	Add in DlgImage.h 
		public variable 
			make an object m_Image 

		
	in Dialog Image class:
		OnInitDialog
		test the function 
		it is initialized at the beginning. 
		
		make the object m_image : create the image 
		
		
		add virtual function: 
		 
		
	but need to display 
	--> class wizard --> add message 
	use WM_PAINT 
		delete button from class wizard 
		
		WM_PAINT --> OnPaint function create 
		draw object m_image 
			use m_image.Draw(&dc)
			--> draw on child window. 
	module the function: make function
		InitImage 
			
	Modify the dialog size created by resource 
		MoveWindow function 
		
	
	change Dlgimage 
		style -> change popup to child 
		--> attach this one to MainDialog 
	change parent: 
		gProjectDlg.cpp: 
			OnInitDialog
				MoveWindow(0, 0, 1280, 800); // Main dialog has size 1280x800 
			--> the child inside the window parent 
		
		still movable the dialog inside 
		DlgImage --> turn off Title Bar 
		-> only image, cannot move inside the main dialog anymore. 

			delete redundant button in child dialog 
			main dialog: all button change to not visiblae 
		
			gProjectDlg : 
				make not visible 
		
		delete button: 
			Ctrl + Shift +x 
				--> method 
			--> delete OnBnClickedDlig 
			then delete button. 
				error then delete related remain 
	
	make 2 place to display image 
		then add 2: 
				make another pointer in header file 
				then in cpp: 
				make another object CDlgImage and do similar. 
				
		m_pDlgImage; another one add too 
		move two dialog to correct position in main dialog.cpp 
			MoveWindow : 
			1 at 0, 0, 640, 480, 
			2 at 640, 0, 640, 480
	
	Add function to Button Test : in main window 
		Button Test 
			use pointer to move: 
			first move to left then move to right 
			
			make a fm point to left: 
			
		GetBits return void --> need to adjust type of data out: 
			unsigned char* pointer. 
		
		update dialog content: 
		dialog->Invalidate() 
		
		test: add 100 black pixel to the dialog child 
		
		then make fucntion to count how many black pixel 
		-> matched. 
		show position of each black pixel. 
		
		save to output about the points. 
		
		
	4.5 
	copy screen to other screen. 
		2objects CDlgImage was created. 
		
		check memory leak because of 2 object. 
		
		Use OnPaint: 
		
		draw, 
		make a member variable in DlgImage.h 
		make a function drawData(CDC* pDC) for object. 
		
		test drawData func : 
		CRect rect(0, 0, 640, 480); 
		pDC->Ellipse(rect);
		
		2object draw 2 ellipse 
		
		copy data from left to right windows. 
		
		random point 
		a point 2 values --> 
			rect.SetRect(point1, point2); 
		
		Make the copy function in Main window gProjectDlg.cpp
		Make value in one frame 
		
		scan left frame, save to data of right object.  
		
		
		nIndex after 1 time press --> 100
		but later it increase then it conflicted. 
		
		// set background of left frame to white 
		memset(fm, 0xff, sizeof(unsigned char) * nWidth * nHeight);
		
		copy from left to right 
		
		
	now go back to DlgImage.cpp 
		change color in drawData : 
		change the pen to new pen. 
		save oldPen 
		draw with new pen 
		set back oldPen 
		
4-6 : change conditions: 
	point is 0 background is 255 
	
	change: background: 0, noise: rand()%0xff 
	set m_pDlgImgResult->m_nDataCount = 0 to count again. 
	
	put define color into stdafx.h 
	put define MAX_POINT 1000 
	Ctrl +Shift + F --> find all 
	
	increase speed: 
4-7	Image processing 
	THere is project class 
	image class 
	make another class for image processing: 
		Ctrl +Shift + X 
		-> Add class --> MFC class 
		this one does not display or do anything 
		-> base class : CObject 
		
		Add function in CObject class. 
		check running time of a process. 
		
		#include <chrono>
		--> calculate time 
		
		processing time is fast, try with large image 
		4096*10   4096*10 -> 1900ms 
		CHange to release version. --> 1300ms 
		
4.8 pattern generate and center weight 
	Do similar as show random point on the result. 
	
	calculate center value: 
	
