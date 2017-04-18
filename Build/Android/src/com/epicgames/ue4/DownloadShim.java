package com.epicgames.ue4;

import com.senai.cyclistv2r.OBBDownloaderService;
import com.senai.cyclistv2r.DownloaderActivity;


public class DownloadShim
{
	public static OBBDownloaderService DownloaderService;
	public static DownloaderActivity DownloadActivity;
	public static Class<DownloaderActivity> GetDownloaderType() { return DownloaderActivity.class; }
}

