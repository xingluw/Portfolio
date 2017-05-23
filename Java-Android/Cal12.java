package com.xorj.project.einstein;

import android.app.Fragment;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.WebSettings;
import android.webkit.WebView;

public class Cal12 extends Fragment {

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.website,
                container, false);

        WebView myWebView = (WebView) view.findViewById(R.id.webview);
        myWebView.loadUrl("http://fhtsscienceacademy.ca/grade-12s-calendar/");
        WebSettings webSettings = myWebView.getSettings();
        webSettings.setJavaScriptEnabled(true);

        return view;
    }
}