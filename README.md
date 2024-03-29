# MVT
Mouse Vocal  Trainer: A hardware-software suite used to classically condition vocal usage and vocal modification by an animal

This project aims to develope a system in which mice (or other animals) could be trained to modify their vocal behavior for a food reward. By adapting innate vocal behaviors in this functional manner, one could explore vocal usage learning or vocal production learning (Petkov and Jarvis, 2012) in a species of interest.

Signficant parts of this project have been tied in from various sources and are highlighted below:

**1) AMVOC - Analysis of Mouse Vocal Communication:**
[AMVOC]((https://github.com/tyiannak/amvoc)) is a collaboration between the Jarvis Lab and the [Multimedia Analysis Group](https://labs-repos.iit.demokritos.gr/MagCIL/about.html) at NCSR-Demoktritos headed by [Dr. Theodoros Giannakopoulos](https://tyiannak.github.io/). AMVOC provides several functionalities for researchers studying ultrasonic vocalizations (USVs), one of which is the ability to detect USVs in real time. More information can be found in our [preprint on BioRxiv](https://www.biorxiv.org/content/10.1101/2021.08.13.456283v1)

**2) FED - Feeding Experimental Device**
[FED](https://github.com/KravitzLabDevices/FED3) is a project out of the [Kravitz lab](https://kravitzlab.com/) at WashU-St. Louis. Because it is Arduino-based, the FED is a great low-cost tool to customizing any part of an experiment that requires pellet delivery as part of the experimental design. The version of the FED code that I have modified and used in this project is found within this repo. The primary addition was adding another "mode" in which the FED operates in a closed-loop manner. It feels hacky  and one day I might try to do it properly, but I simply prevent the Feather M0 from reading the battery's charge and instead use `pin 9` as an analog input source. 

Of course MVT can be used with non-food rewards like sugar  water, chocolate, etc., but I just haven't gotten around to trying other things. The FED simply receives a trigger signal when a USV is detected by AMVOC, so the device receiving the trigger really be anything you want/need in your set up. In our case using the pellets, when the Feather receives a `high` value it will trigger FED to provide a pellet. For experimental, and obvious, reasons only one pellet is provided at a time to prevent pile ups. So even if many trigger signals are sent to the FED, until the first pellet is removed, new pellets will not be provided.

A major goal of this project as well has been to make it open source and low-cost. The most expensive component used in our set up is the ultrasonic microphone (Ultramic 384K BLE). At ~$400, this microphone is still cheaper than almost any other avilable ultrasonic microphone. Considering it's a USB microphone, it also provides the easies user experience compared to many that require boards form NIDAQ or expensive hardware ecosystems from Avisoft. As it's currently  designed, MVA currently costs about ~$1000.

# Materials and Set Up

## Materials
All prices converted to USD
1) [Ultramike 384K BLE](https://www.dodotronic.com/product/ultramic-384k-ble/?v=2a47ad90f2ae) - $410
2) [NVIDIA Jetson Nano](https://www.amazon.com/dp/B08J157LHH) - $59
3) Screen for Jetson - we used the [7inch Capacitive Touch Screen](https://www.amazon.com/7inch-HDMI-LCD-Capacitive-Screen/dp/B07P8P3X6M/ref=pd_di_sccai_2/130-9375513-5800917?pd_rd_i=B07P8P3X6M&pd_rd_r=5dda8150-b824-4b5c-9f74-b6f0819ddfc6&pd_rd_w=3ov4w&pd_rd_wg=AmbDO&pf_rd_p=c9443270-b914-4430-a90b-72e3e7e784e0&pf_rd_r=CYZQF73J3FGMV857Y7KJ&psc=1) from Waveshare - $65
4) FED
   - 3D printing yourself - $200-300 depending on 3D printing costs
   - Purchase form [Open Ephys Produciton Site](https://open-ephys.org/fed3/fed3) - $240
5) [Firefly S](https://www.flir.com/products/firefly-s/?model=FFY-U3-16S2C-S) - $199
6) [3mm FL f/2.5, Blue Series M12 Lens ](https://www.edmundoptics.com/p/3mm-fl-f25-blue-series-m12-mu-videotrade-imaging-lens/31866/) - $95
7) [JST GPIO Connector](https://www.flir.com/products/jst-gpio-connector-for-firefly-s-dl-and-bfs-bd/) - $8

The camera is optional for the basic goals and function of this project, but it certianly can be be useful. We run it off a desktop so as not to interfere with audio processing from AMVOC. In our case it also facilitates monitoring the health of the animals in addition to monitoring their behavior.

### Other Components
Please see the "Designs" folder for .stl files for 3D printed components (screen and Jetson Nano holder, and camera holder), and .ai files for laser cutting plans for the home cage set-up.

## AMVOC Set Up
For the NVIDIA Jetson Nano, it's a bit tricky but it works out fairly well and all dependancies can be installed. We would also recommed ensuring that you use Python 3.7 as that is what was used to develop this system. Not all libraries play nice if your python3 is below or above (at the dat of writing this September, 2023).
Installation and code execution is done through Terminal
Note: The Jetson  Nano does not naitively have WiFi capabilities so you'll need an Ethernet connection or buy the WiFi adapter.
1) Install AMVOC

   `git clone https://github.com/tyiannak/amvoc`

2) In the requirements.txt file, comment out torch, torchvision, pyaudio, and umap
3) cd to AMVOC folder and install requirements

   `pip3 install -r requirements.txt`

4) [Follow instrucitons from Q-engineering for installing torch and torchvision](https://qengineering.eu/install-pytorch-on-jetson-nano.html) (**ensure versions are compatible**)
5) Install pyaudio (no idea why, but some part of the process for installing torch and torchvision makes this installation really smooth. I constantly had issues when I would try  installing it with the other dependencies).

   `pip install PyAudio`
6) Edit `main_live.py` to provide outputs via the Jetson Nano GPIO.
8) Using Terminal run `python3 main_live.py' to get going!

When running `main_live.py` it will prompt you to enter the sampling frequency you want to use (this will depend on your microphones capabilities). Next you'll see a list of the available audio devices, simply type the index of the microphone you'd like to use. As soon as you hit `enter` the script will start and will begin sampling audio to detect USVs!

Note: You can also change the `mid_buffer_size` which is the amount of time AMVOC will stream audio data to process (i.e. a value of `0.75` means AMVOC will process 750ms of data at a time - with some overlap between chunks built-in). 750ms was chosen to maximize detection accuracy but this can be changed as desired.

## Basic Layout of Equipment
![Equipment layout](https://github.com/cvargas4/MouseVocalTrainer/blob/main/Images/MVT_Schematic_v2.png)
