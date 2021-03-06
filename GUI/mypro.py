'''
Multitouch Image Viewer
-----------------------

Author:Anil,Jijo,KP
Date:2-04-2011
College:FISAT,Kerala

'''
import cv
import random
from os.path import join, dirname, exists
from pymt import *
import Image
import ImageChops
sizethumb=100,75
current_dir = dirname(__file__)
iext=["png","jpeg","jpg","gif","bmp"]
vext=["flv","mpg","mpeg","avi","mkv"]
thumb = join(current_dir, 'video.png')
class Desktop(MTBoxLayout):
    layout_def = '''
    <MTBoxLayout orientation='"vertical"' cls='"desktop-background"'>
        <MTWidget size_hint='(1, .7)' cls='"draw-board"' id='"mainwidget"'/>
        <MTAnchorLayout size_hint='(1, .3)'>
            <MTBoxLayout cls='"form"' padding='2' orientation='"horizontal"'>
                <MTButton size_hint='(.1,1)' id='"select"' label='"Go"' cls='"select_button"' anchor_x='"center"'/>
                <MTCoverFlow size_hint='(.9,1)' reflection_percent='0.5' cover_spacing='35' cls='"image-coverflow"'
            thumbnail_size='(100, 75)' cover_distance='100' reflection_start='0.8' reflection_stop='0.25' id='"coverflow"'/>
            </MTBoxLayout>
        </MTAnchorLayout>
    </MTBoxLayout>
    '''

    def __init__(self, **kwargs):
        super(Desktop, self).__init__(**kwargs)
        self.xml = xml = XMLWidget(xml=Desktop.layout_def)
        self.xml.autoconnect(self)
        self.add_widget(self.xml.root)
        self.coverflow = xml.getById('coverflow')
        self.clickme = xml.getById('select')
        self.drawscreen = xml.getById('mainwidget')
        self.fileselect=MTFileBrowser(size=(450,450),title="File me!",multipleselection="TRUE",path="/home")
        self.clickme.connect('on_press',curry(self.on_clickme_pressed))
        self.fileselect.connect('on_select',curry(self.on_file_selected))
        self.fileselect.connect('on_cancel',curry(self.on_file_cancel))
        self.coverflow.connect('on_select',curry(self.on_coverflow))
	self.vflag=False
	self.scat=''
	self.video=''
	self.imagex=''
        self.selectedfiles=''
        self.m=''
        self.mw=''
        
        
        

    
# ###########################################################
    def populate(self,list):
        global iext
        global vext
        lis=list
        for filen in lis:
            
            e=''
            ext=filen[-4:]
            if ext[0]=='.':
                e=ext[1:]
            else :
                e=ext
            
            
                
            #mib=MTImageButton(filename=filen)
            #print e
            if e in iext:
                #print filen
	        im=Image.open(filen)
                #im.thumbnail(sizethumb, Image.ANTIALIAS)
		#print im.size
		im=im.resize((100,75),Image.ANTIALIAS)
		#print im.size
		im.save("thumb.jpg")
                mib=MTImageButton(filename="thumb.jpg")
                mib.type=e
                mib.infos=filen
                self.coverflow.add_widget(mib)
            elif e in vext:
                tmp=current_dir+"video.png"
		film=Image.open("vtemp.jpg")
		capture=cv.CaptureFromFile(filen)
		vrand=random.randint(500,1500)
		cv.SetCaptureProperty(capture,cv.CV_CAP_PROP_POS_FRAMES,vrand)
		cvimg=cv.QueryFrame(capture)
		cv.SaveImage("thumb.jpg",cvimg)
		vt=Image.open("thumb.jpg")
		vt=vt.resize((100,75),Image.ANTIALIAS)
		fin=ImageChops.multiply(vt,film)
		fin.save("vthumb.jpg")
		
		
                print current_dir
                mib=MTImageButton(filename="vthumb.jpg")
                mib.type=e
                mib.infos=filen
                self.coverflow.add_widget(mib)

            
    
	   
    def on_file_cancel(self):
        self.m.remove_widget(self.mw)
    def on_file_selected(self,list):
        
        self.m.remove_widget(self.mw)
        listx=list
        
        self.populate(listx)
        
        
        
    def on_clickme_pressed(self,*largs):
        
        self.mw=MTModalWindow()
        self.m=getWindow()
        self.m.add_widget(self.mw)
        self.mw.add_widget(self.fileselect)
        
    def on_close_resize(self,widget,*largs):
	tmp=widget.scale
	if(tmp<0.17):
		if(widget.name==1):
			self.vflag=False
			self.video._on_toggle_mute()
			self.drawscreen.remove_widget(widget)
		else:
			self.drawscreen.remove_widget(widget)
    def on_coverflow(self, widget):
        global iext
        global vext
     
        inf=widget.infos
        ext=widget.type
        rnscale=random.random()
        rnrot=random.randint(0,75)
        
        if rnscale<0.3:
            rnscale=0.3
        elif rnscale>0.5:
            rnscale=0.5
        if ext in iext:
            self.imagex = MTScatterImage(filename=inf,scale=rnscale,rotation=rnrot)
	    #self.imagex.connect('on_move',curry(self.on_close_resize,self.imagex))
	    self.imagex.name=0
	    self.imagex.connect('on_transform',curry(self.on_close_resize,self.imagex))
	    
            self.drawscreen.add_widget(self.imagex)
        elif ext in vext:
            
               
            
            if self.vflag==True:
		self.video._on_toggle_mute()
		self.scat.remove_widget(self.video)
		self.drawscreen.remove_widget(self.scat)
	    else:
		self.vflag=False

	
	    self.video=MTVideo(filename=inf, autostart=True)
	    self.scat=MTScatterWidget(size=self.video.size,rotation=rnrot)
            connect(self.video, 'on_resize', self.scat, 'size')
	    #connect(self.video, 'on_resize', self, 'on_close_resize',curry(self.on_close_resize,self.scat))
	    #self.video.push_handlers(on_resize=curry(self.on_close_resize,self.video))
	    self.video.hide_controls()
	    self.scat.name=1
            self.scat.add_widget(self.video)
	    self.scat.connect('on_transform',curry(self.on_close_resize,self.scat))
	    #self.scat.push_handlers(on_resize=curry(self.on_close_resize,self.scat))
	    #connect('on_resize',curry(self.on_close_resize,self.scat))
            self.drawscreen.add_widget(self.scat)
	
            


        
    
if __name__ == '__main__':
    with open(join(current_dir, 'desktop-single.css')) as fd:
        css_data = fd.read() % dict(fontpath=join(current_dir, ''))
    css_add_sheet(css_data)
   
    runTouchApp(Desktop())
