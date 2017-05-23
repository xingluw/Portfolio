package com.xorj.project.einstein;

import android.app.Fragment;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class Messages extends Fragment {

    private ListView lvHomePage;
    private String[] items;
    private View view;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.showmessages, container, false);

        return view;
    }

    @Override
    public void onActivityCreated(@Nullable Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);

        items = view.getResources().getStringArray(R.array.messagelist);
        lvHomePage = (ListView) view.findViewById(R.id.msglist);

        lvHomePage.setAdapter(new ArrayAdapter< String>(view.getContext(),
                android.R.layout.simple_list_item_1, items));
    }
}


/**
 * public class Messages extends Fragment {
 * private ListView lvHomePage;
 * private String[] items;
 *
 * @Override public View onCreateView(LayoutInflater inflater, ViewGroup container,
 * Bundle savedInstanceState) {
 * View view = inflater.inflate(R.layout.showmessages,
 * container, false);
 * return view;
 * <p/>
 * <p/>
 * items = view.getResources().getStringArray(R.array.messagelist);
 * lvHomePage = (ListView) view.findViewById(R.id.msglist);
 * <p/>
 * lvHomePage.setAdapter(new ArrayAdapter<String>(getActivity().getApplicationContext(),
 * android.R.layout.simple_list_item_1 , items));
 * <p/>
 * return view;
 * }
 * }
 **/

