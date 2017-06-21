package com.epicgames.ue4;

import com.segalla.vrcycle.OBBDownloaderService;
import com.segalla.vrcycle.DownloaderActivity;


public class DownloadShim
{
	public static OBBDownloaderService DownloaderService;
	public static DownloaderActivity DownloadActivity;
	public static Class<DownloaderActivity> GetDownloaderType() { return DownloaderActivity.class; }
}

